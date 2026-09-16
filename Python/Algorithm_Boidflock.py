"""
Boids flocking simulation (Craig Reynolds, 1986)

Each fish only reacts to its nearby neighbors using three simple rules:
  - Separation: steer away from fish that are too close
  - Alignment:  match the average heading of nearby fish
  - Cohesion:   steer toward the average position of nearby fish
Plus one more rule for the predator:
  - Flee: steer hard away from the shark (weighted heavier than the rest)

No single fish "knows" it's part of a school -- the swirling shape you see
emerges purely from these local rules running on every fish, every frame.

Controls:
  - Click/tap the water to send a shark through the school
  - Drag the sliders to change separation / alignment / cohesion strength
  - "auto-shark" toggles a shark that drives itself through the school
  - "reset" respawns the fish

Run with:  pip install pygame
           python boids.py
"""

import pygame
import random
import math
import sys

# ---------------------------------------------------------------- settings
WIDTH, HEIGHT = 900, 700
SIM_HEIGHT = 560          # area the fish swim in (rest is UI panel)
BG_COLOR = (8, 8, 12)
PANEL_COLOR = (14, 14, 20)
FISH_COLOR = (235, 235, 240)
SHARK_COLOR = (255, 60, 120)
INFECTED_COLOR = SHARK_COLOR      # infected fish match the shark's color
ACCENT = (255, 60, 120)
TEXT_COLOR = (150, 150, 160)

MAX_SPEED = 4.0
MIN_SPEED = 1.5
PERCEPTION = 55       # how far a fish can "see" its neighbors
SEPARATION_DIST = 22  # personal space before separation kicks in
SHARK_FLEE_RADIUS = 150
SHARK_TOUCH_DIST = 18  # how close the shark must get to actually "infect" a fish
SHARK_SPEED = 5.5

FPS = 30


# --------------------------------------------------------------- the fish
class Boid:
    def __init__(self):
        self.pos = pygame.Vector2(random.uniform(0, WIDTH),
                                   random.uniform(0, SIM_HEIGHT))
        angle = random.uniform(0, 2 * math.pi)
        speed = random.uniform(MIN_SPEED, MAX_SPEED)
        self.vel = pygame.Vector2(math.cos(angle), math.sin(angle)) * speed
        self.infected = False  # turns True once a shark touches this fish

    def flock(self, boids, shark_pos, sep_w, align_w, coh_w):
        separation = pygame.Vector2()
        avg_vel = pygame.Vector2()
        avg_pos = pygame.Vector2()
        neighbor_count = 0

        # look at every other fish; only react to the ones close enough
        for other in boids:
            if other is self:
                continue
            offset = other.pos - self.pos
            dist = offset.length()
            if 0 < dist < PERCEPTION:
                neighbor_count += 1
                avg_vel += other.vel
                avg_pos += other.pos
                if dist < SEPARATION_DIST:
                    separation -= offset / dist  # push away, stronger when closer

        alignment = pygame.Vector2()
        cohesion = pygame.Vector2()
        if neighbor_count > 0:
            avg_vel /= neighbor_count
            alignment = avg_vel - self.vel

            avg_pos /= neighbor_count
            cohesion = avg_pos - self.pos

        # flee the shark -- overrides everything else when it's close
        flee = pygame.Vector2()
        if shark_pos is not None:
            offset = self.pos - shark_pos
            dist = offset.length()
            if 0 < dist < SHARK_FLEE_RADIUS:
                strength = (SHARK_FLEE_RADIUS - dist) / SHARK_FLEE_RADIUS
                flee = offset.normalize() * strength * MAX_SPEED

        steer = (separation * sep_w * 1.6
                 + alignment * align_w
                 + cohesion * coh_w * 0.08
                 + flee * 3.0)

        self.vel += steer * 0.06
        speed = self.vel.length()
        if speed > MAX_SPEED:
            self.vel.scale_to_length(MAX_SPEED)
        elif speed < MIN_SPEED and speed > 0:
            self.vel.scale_to_length(MIN_SPEED)

    def move(self):
        self.pos += self.vel
        # wrap around the tank edges
        self.pos.x %= WIDTH
        self.pos.y %= SIM_HEIGHT

    def draw(self, screen):
        angle = math.atan2(self.vel.y, self.vel.x)
        size = 6
        tip = self.pos + pygame.Vector2(math.cos(angle), math.sin(angle)) * size
        left = self.pos + pygame.Vector2(math.cos(angle + 2.6), math.sin(angle + 2.6)) * size * 0.7
        right = self.pos + pygame.Vector2(math.cos(angle - 2.6), math.sin(angle - 2.6)) * size * 0.7
        color = INFECTED_COLOR if self.infected else FISH_COLOR
        pygame.draw.polygon(screen, color, [tip, left, right])


# --------------------------------------------------------------- the shark
SHARK_LIFESPAN = FPS * 10   # frames before the shark gives up and leaves
SHARK_TURN_RATE = 0.10      # how quickly it can change direction while hunting


class Shark:
    """A predator that actively hunts the nearest fish, then swims off."""

    def __init__(self, entry_point):
        self.pos = pygame.Vector2(entry_point)
        self.pos.x = -40 if entry_point[0] > WIDTH / 2 else WIDTH + 40
        self.vel = pygame.Vector2(1 if self.pos.x < 0 else -1, 0) * SHARK_SPEED
        self.alive = True
        self.age = 0
        self.leaving = False

    def update(self, boids):
        self.age += 1

        if not self.leaving and self.age > SHARK_LIFESPAN:
            self.leaving = True

        if self.leaving:
            # swim off in whatever direction it was already heading
            desired = self.vel.normalize() if self.vel.length() > 0 else pygame.Vector2(1, 0)
        elif boids:
            # find the nearest fish and chase it -- recomputed every frame,
            # so the shark tracks the school as it scatters and regroups
            nearest = min(boids, key=lambda b: self.pos.distance_squared_to(b.pos))
            offset = nearest.pos - self.pos
            desired = offset.normalize() if offset.length() > 0 else self.vel
        else:
            desired = self.vel.normalize() if self.vel.length() > 0 else pygame.Vector2(1, 0)

        # steer smoothly toward the desired direction instead of snapping to it,
        # so the shark's turns look natural rather than teleporting its heading
        self.vel = self.vel.lerp(desired * SHARK_SPEED, SHARK_TURN_RATE)
        if self.vel.length() > 0:
            self.vel.scale_to_length(SHARK_SPEED)
        self.pos += self.vel

        if self.pos.x < -60 or self.pos.x > WIDTH + 60:
            self.alive = False

    def draw(self, screen):
        angle = math.atan2(self.vel.y, self.vel.x) if self.vel.length() > 0 else 0
        size = 16
        tip = self.pos + pygame.Vector2(math.cos(angle), math.sin(angle)) * size
        left = self.pos + pygame.Vector2(math.cos(angle + 2.6), math.sin(angle + 2.6)) * size * 0.8
        right = self.pos + pygame.Vector2(math.cos(angle - 2.6), math.sin(angle - 2.6)) * size * 0.8
        pygame.draw.polygon(screen, SHARK_COLOR, [tip, left, right])


# ------------------------------------------------------------------ slider
class Slider:
    def __init__(self, x, y, w, label, min_val, max_val, value, decimals=1):
        self.rect = pygame.Rect(x, y, w, 6)
        self.label = label
        self.min_val = min_val
        self.max_val = max_val
        self.value = value
        self.decimals = decimals
        self.dragging = False

    def handle_pos(self):
        t = (self.value - self.min_val) / (self.max_val - self.min_val)
        return int(self.rect.x + t * self.rect.width)

    def handle_event(self, event):
        handle_x = self.handle_pos()
        handle_rect = pygame.Rect(handle_x - 10, self.rect.y - 8, 20, 22)
        if event.type == pygame.MOUSEBUTTONDOWN:
            if handle_rect.collidepoint(event.pos) or self.rect.collidepoint(event.pos):
                self.dragging = True
                self._set_from_mouse(event.pos[0])
        elif event.type == pygame.MOUSEBUTTONUP:
            self.dragging = False
        elif event.type == pygame.MOUSEMOTION and self.dragging:
            self._set_from_mouse(event.pos[0])

    def _set_from_mouse(self, mx):
        t = (mx - self.rect.x) / self.rect.width
        t = max(0, min(1, t))
        self.value = self.min_val + t * (self.max_val - self.min_val)
        if self.decimals == 0:
            self.value = round(self.value)

    def draw(self, screen, font):
        pygame.draw.rect(screen, (50, 50, 58), self.rect, border_radius=3)
        hx = self.handle_pos()
        pygame.draw.circle(screen, ACCENT, (hx, self.rect.y + 3), 9)

        label_surf = font.render(self.label, True, TEXT_COLOR)
        screen.blit(label_surf, (self.rect.x, self.rect.y - 22))

        val_text = f"{self.value:.{self.decimals}f}" if self.decimals else str(int(self.value))
        val_surf = font.render(val_text, True, ACCENT)
        screen.blit(val_surf, (self.rect.x + self.rect.width - val_surf.get_width(), self.rect.y - 22))


# ------------------------------------------------------------------ button
class Button:
    def __init__(self, x, y, w, h, label):
        self.rect = pygame.Rect(x, y, w, h)
        self.label = label
        self.active = False

    def draw(self, screen, font):
        color = ACCENT if self.active else (70, 70, 78)
        pygame.draw.rect(screen, color, self.rect, width=2, border_radius=16)
        text = font.render(self.label, True, color)
        screen.blit(text, text.get_rect(center=self.rect.center))

    def clicked(self, pos):
        return self.rect.collidepoint(pos)


def make_boids(n):
    return [Boid() for _ in range(n)]


def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("school.py -- boids simulation")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("consolas", 16)
    small_font = pygame.font.SysFont("consolas", 14)

    fish_count = 180
    boids = make_boids(fish_count)
    sharks = []
    auto_shark_timer = 0

    sep_slider = Slider(30, 620, 300, "separation", 0.0, 3.0, 1.4)
    align_slider = Slider(380, 620, 300, "alignment", 0.0, 3.0, 1.0)
    coh_slider = Slider(30, 670, 300, "cohesion", 0.0, 3.0, 1.0)
    count_slider = Slider(380, 670, 300, "fish count", 20, 400, fish_count, decimals=0)
    sliders = [sep_slider, align_slider, coh_slider, count_slider]

    code_btn = Button(30, 715, 90, 34, "code")
    auto_btn = Button(140, 715, 170, 34, "auto-shark: off")
    reset_btn = Button(330, 715, 90, 34, "reset")
    buttons = [code_btn, auto_btn, reset_btn]

    auto_shark = False
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if auto_btn.clicked(event.pos):
                    auto_shark = not auto_shark
                    auto_btn.label = f"auto-shark: {'on' if auto_shark else 'off'}"
                elif reset_btn.clicked(event.pos):
                    boids = make_boids(int(count_slider.value))
                    sharks = []
                elif event.pos[1] < SIM_HEIGHT:
                    # tap the water -> send a shark through from the tapped point
                    target = (event.pos[0], event.pos[1])
                    sharks.append(Shark(target))

            for s in sliders:
                s.handle_event(event)

        # fish count slider changed -> grow/shrink the school
        target_count = int(count_slider.value)
        if target_count != len(boids):
            if target_count > len(boids):
                boids.extend(make_boids(target_count - len(boids)))
            else:
                boids = boids[:target_count]

        # auto-shark: launch one periodically
        if auto_shark:
            auto_shark_timer -= 1
            if auto_shark_timer <= 0 and not sharks:
                y = random.uniform(60, SIM_HEIGHT - 60)
                sharks.append(Shark((WIDTH / 2, y)))
                auto_shark_timer = FPS * 4

        shark_pos = sharks[0].pos if sharks else None

        for b in boids:
            b.flock(boids, shark_pos, sep_slider.value, align_slider.value, coh_slider.value)
        for b in boids:
            b.move()

        for s in sharks:
            s.update(boids)
        sharks = [s for s in sharks if s.alive]

        # any fish close enough to a shark gets marked infected
        for s in sharks:
            for b in boids:
                if b.pos.distance_to(s.pos) < SHARK_TOUCH_DIST:
                    b.infected = True

        # ---- draw ----
        screen.fill(BG_COLOR)
        pygame.draw.rect(screen, PANEL_COLOR, (0, SIM_HEIGHT, WIDTH, HEIGHT - SIM_HEIGHT))

        for b in boids:
            b.draw(screen)
        for s in sharks:
            s.draw(screen)

        header = font.render(f"{len(boids)} fish  ·  {FPS} fps", True, TEXT_COLOR)
        screen.blit(header, (WIDTH - header.get_width() - 20, 16))
        title = font.render("school.py", True, ACCENT)
        screen.blit(title, (20, 16))

        if not sharks:
            hint = small_font.render("tap the water to send a shark through the school", True, (90, 90, 98))
            screen.blit(hint, hint.get_rect(center=(WIDTH // 2, SIM_HEIGHT - 20)))

        for s in sliders:
            s.draw(screen, small_font)
        for btn in buttons:
            btn.draw(screen, small_font)

        pygame.display.flip()
        clock.tick(FPS)

    pygame.quit()
    sys.exit()


if __name__ == "__main__":
    main()