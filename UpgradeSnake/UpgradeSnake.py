import pygame
import random
import sys
from collections import deque
import time
import tkinter as tk
import os

# --- Constants ---
GRID_SIZE = 20
CELL_SIZE = 30
SCREEN_SIZE = GRID_SIZE * CELL_SIZE
FPS = 15 
WALL_COUNT = 30 
MAX_HUNGER = 50 
MAX_THIRST = 50 

# --- Colors ---
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
DARK_GREEN = (0, 100, 0)
RED = (255, 0, 0)
BLUE = (0, 100, 255)
GRAY = (100, 100, 100)
BLACK = (0, 0, 0)
PURPLE = (200, 0, 200)
CYAN = (0, 255, 255)

# --- Pygame init ---
pygame.init()
screen = pygame.display.set_mode((SCREEN_SIZE, SCREEN_SIZE + 60))
pygame.display.set_caption("Snake with Hunger & Thirst")
clock = pygame.time.Clock()
font = pygame.font.SysFont("Arial", 24)

player_money = 0
SAVE_FILE = "allSnakeSaves.txt"

upgrades = {
    "slower_snake": {
        "current": FPS,
        "min": 5,
        "step": -0.25,
        "base_price": 10,
        "price_scale": 1.20,
        "purchases": 0
    },
    "max_hunger": {
        "current": MAX_HUNGER,
        "step": 2,
        "base_price": 2,
        "price_scale": 1.05,
        "purchases": 0
    },
    "max_thirst": {
        "current": MAX_THIRST,
        "step": 2,
        "base_price": 2,
        "price_scale": 1.05,
        "purchases": 0
    },
    "less_walls": {
        "current": WALL_COUNT,
        "min": 0,
        "step": -1,
        "base_price": 100,
        "price_scale": 1.5,
        "purchases": 0
    },
    "plus_length": {
        "current": 0,
        "step":1,
        "base_price": 101,
        "price_scale": 1.75,
        "purchases": 0
    },
    "money_yield": {
        "current": 1,
        "step": 1,
        "base_price": 1,
        "price_scale": 5.0,
        "purchases": 0
    }
}

# --- Save/Load Functions ---

def save_game(name_entry):
    global player_money
    name = name_entry.get().lower().strip()
    if not name: return

    all_data = {}
    if os.path.exists(SAVE_FILE):
        with open(SAVE_FILE, "r") as f:
            for line in f:
                parts = line.strip().split("|")
                if len(parts) == 3:
                    all_data[parts[0]] = line.strip()

    p_data = ",".join([str(u["purchases"]) for u in upgrades.values()])
    # Force 2 decimal places on save
    all_data[name] = f"{name}|{player_money:.2f}|{p_data}"

    with open(SAVE_FILE, "w") as f:
        for entry in all_data.values():
            f.write(entry + "\n")

def load_game(name_entry, labels):
    global player_money
    name = name_entry.get().lower().strip()
    if not os.path.exists(SAVE_FILE): return

    with open(SAVE_FILE, "r") as f:
        for line in f:
            parts = line.strip().split("|")
            if parts[0] == name:
                player_money = float(parts[1])
                purchases = parts[2].split(",")
                
                # Dictionary of defaults for recalculation
                defaults = {
                    "slower_snake": 15, 
                    "max_hunger": 50, 
                    "max_thirst": 50, 
                    "less_walls": 30, 
                    "plus_length": 0,
                    "money_yield": 1
                }

                for i, key in enumerate(upgrades.keys()):
                    if i < len(purchases):
                        p_count = int(purchases[i])
                        upgrades[key]["purchases"] = p_count
                        # Follow the existing "current" calculation pattern
                        if key != "plus_length":
                            upgrades[key]["current"] = defaults[key] + (upgrades[key]["step"] * p_count)
                break
    
    labels["money"].config(text=f"Money: {player_money:.2f}")
    for key, u in upgrades.items():
        curr_val = u["current"] if key != "plus_length" else u["purchases"]
        labels[key]["current"].config(text=f"{curr_val:.2f}" if key != "plus_length" else f"{int(curr_val)}")
        next_val = "Sold Out" if "min" in u and u["current"] <= u["min"] else round(u.get("current", u.get("purchases", 0)) + u.get("step", 1), 2)
        labels[key]["next"].config(text=f"{next_val:.2f}" if isinstance(next_val, float) else next_val)
        labels[key]["price"].config(text=f"{upgrade_price(u):.2f}" if next_val != "Sold Out" else "—")

# --- Drawing and Game Functions ---

def draw_cell(pos, color):
    x, y = pos
    pygame.draw.rect(screen, color, (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE))

def draw_bar(x, y, width, height, current, maximum, color, border_color=WHITE):
    pygame.draw.rect(screen, border_color, (x, y, width, height), 2)
    fill_width = int(width * (current / maximum))
    pygame.draw.rect(screen, color, (x, y, fill_width, height))

def draw_hunger_bar(hunger):
    draw_bar(10, SCREEN_SIZE + 5, SCREEN_SIZE - 20, 20, hunger, MAX_HUNGER, RED)

def draw_thirst_bar(thirst):
    draw_bar(10, SCREEN_SIZE + 30, SCREEN_SIZE - 20, 20, thirst, MAX_THIRST, BLUE)

def is_reachable(start, walls, snake, min_reachable=GRID_SIZE * GRID_SIZE // 4):
    visited = set()
    queue = deque([start])
    reachable_count = 0
    while queue:
        cell = queue.popleft()
        if cell in visited: continue
        visited.add(cell)
        reachable_count += 1
        x, y = cell
        for nx, ny in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
            if 0 <= nx < GRID_SIZE and 0 <= ny < GRID_SIZE:
                if (nx, ny) not in walls and (nx, ny) not in snake and (nx, ny) not in visited:
                    queue.append((nx, ny))
    return reachable_count >= min_reachable

def random_empty_cell(snake, walls, forbidden=None):
    while True:
        pos = (random.randint(0, GRID_SIZE - 1), random.randint(0, GRID_SIZE - 1))
        if pos not in snake and pos not in walls and (forbidden is None or pos != forbidden):
            return pos

def generate_walls(snake):
    max_attempts = 100
    head = snake[0]
    safe_column = head[0]
    gen_direction = (0, -1) 
    for attempt in range(max_attempts):
        walls = set()
        while len(walls) < WALL_COUNT:
            pos = (random.randint(0, GRID_SIZE - 1), random.randint(0, GRID_SIZE - 1))
            if pos not in snake and pos != head:
                if pos[0] == safe_column and pos[1] < head[1]: continue
                front = (head[0] + gen_direction[0], head[1] + gen_direction[1])
                if pos == front: continue
                walls.add(pos)
        if is_reachable(head, walls, snake): return walls
    return set()

def upgrade_price(u):
    price = u["base_price"] * (u["price_scale"] ** u["purchases"])
    return round(price, 2)

def buy_upgrade(key, labels):
    global player_money
    u = upgrades[key]
    price = upgrade_price(u)
    if player_money < price: return
    if "min" in u and u.get("current", 0) <= u.get("min", -1): return

    player_money -= price
    if key != "plus_length":
        u["current"] += u["step"]
    u["purchases"] += 1

    # Standard UI update
    if key != "plus_length":
        labels[key]["current"].config(text=f"{u['current']:.2f}")
        next_val = "Sold Out" if "min" in u and u["current"] <= u["min"] else round(u["current"] + u["step"], 2)
        labels[key]["next"].config(text=f"{next_val:.2f}" if next_val != "Sold Out" else next_val)
    else:
        labels[key]["current"].config(text=u["purchases"])
        labels[key]["next"].config(text=u["purchases"] + 1)

    new_price = "—" if (key != "plus_length" and "min" in u and u["current"] <= u["min"]) else f"{upgrade_price(u):.2f}"
    labels[key]["price"].config(text=new_price)
    labels["money"].config(text=f"Money: {player_money:.2f}")

def show_upgrade_window(snake_length):
    global player_money
    # Logic: (segments - 1 head) * yield
    earned = (snake_length - 1) * upgrades["money_yield"]["current"]
    player_money += max(0, earned)

    root = tk.Tk()
    root.title("Upgrades")
    root.configure(bg="#646464")
    save_ui = tk.Frame(root, bg="#4a4a4a", pady=5)
    save_ui.grid(row=0, column=0, columnspan=6, sticky="ew")
    tk.Label(save_ui, text="Name:", bg="#4a4a4a", fg="white").pack(side="left", padx=5)
    name_entry = tk.Entry(save_ui)
    name_entry.pack(side="left", padx=5)
    labels = {} 
    tk.Button(save_ui, text="Save", command=lambda: save_game(name_entry)).pack(side="left", padx=2)
    tk.Button(save_ui, text="Load", command=lambda: load_game(name_entry, labels)).pack(side="left", padx=2)

    header_font = ("Georgia", 14, "bold")
    normal_font = ("Georgia", 12)
    money_label = tk.Label(root, text=f"Money: {player_money:.2f}", font=header_font, bg="#646464")
    money_label.grid(row=1, column=0, columnspan=6, pady=(10, 5))
    labels["money"] = money_label

    headers = ["Upgrade", "Current", "Next", "Price", "", ""]
    for i, h in enumerate(headers):
        tk.Label(root, text=h, font=header_font, bg="#646464").grid(row=2, column=i, padx=5, pady=5)

    row = 3
    for key, u in upgrades.items():
        labels[key] = {}
        next_val = "Sold Out" if "min" in u and u["current"] <= u["min"] else round(u.get("current", u.get("purchases", 0)) + u.get("step", 1), 2)
        current_display = f"{u.get('current', u.get('purchases', 0)):.2f}" if key != "plus_length" else u['purchases']
        price = "—" if next_val == "Sold Out" else f"{upgrade_price(u):.2f}"

        labels[key]["current"] = tk.Label(root, text=current_display, font=normal_font, bg="#646464")
        labels[key]["current"].grid(row=row, column=1, padx=5, pady=3)
        labels[key]["next"] = tk.Label(root, text=next_val, font=normal_font, bg="#646464")
        labels[key]["next"].grid(row=row, column=2, padx=5, pady=3)
        labels[key]["price"] = tk.Label(root, text=price, font=normal_font, bg="#646464")
        labels[key]["price"].grid(row=row, column=3, padx=5, pady=3)
        tk.Label(root, text=key.replace("_", " ").title(), font=normal_font, bg="#646464").grid(row=row, column=0, padx=5, pady=3)
        tk.Button(root, text="Buy", font=normal_font, width=8, command=lambda k=key: buy_upgrade(k, labels)).grid(row=row, column=4, padx=5, pady=3)
        row += 1

    tk.Button(root, text="Play", font=header_font, width=15, command=root.destroy).grid(row=row, column=0, columnspan=6, pady=10)
    root.update_idletasks()
    root.geometry(f"{root.winfo_reqwidth() + 20}x{root.winfo_reqheight() + 20}")
    root.mainloop()

# --- Main Game Loop ---
def game_loop():
    global FPS, MAX_HUNGER, MAX_THIRST, WALL_COUNT, player_money
    FPS = upgrades["slower_snake"]["current"]
    MAX_HUNGER = upgrades["max_hunger"]["current"]
    MAX_THIRST = upgrades["max_thirst"]["current"]
    WALL_COUNT = upgrades["less_walls"]["current"]
    
    snake = [(10, 10)]
    initial_length = int(upgrades["plus_length"]["purchases"])
    current_pos = snake[0]
    placement_dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    dir_idx = 0
    for _ in range(initial_length):
        placed = False
        attempts = 0
        while not placed and attempts < 4:
            dx, dy = placement_dirs[dir_idx]
            next_seg = (current_pos[0] + dx, current_pos[1] + dy)
            if 0 <= next_seg[0] < GRID_SIZE and 0 <= next_seg[1] < GRID_SIZE and next_seg not in snake:
                snake.append(next_seg)
                current_pos = next_seg
                placed = True
            else:
                dir_idx = (dir_idx + 1) % 4
                attempts += 1
    
    direction = (0, 0)
    walls = generate_walls(snake)
    score = 0
    hunger = MAX_HUNGER
    thirst = MAX_THIRST
    food = random_empty_cell(snake, walls)
    water = random_empty_cell(snake, walls, forbidden=food)
    game_started = False

    screen.fill(BLACK)
    for cell in snake: draw_cell(cell, GREEN)
    draw_cell(snake[0], DARK_GREEN)
    draw_cell(food, RED)
    draw_cell(water, BLUE)
    for wall in walls: draw_cell(wall, GRAY)
    draw_hunger_bar(hunger)
    draw_thirst_bar(thirst)
    overlay_font = pygame.font.SysFont("Arial", 40, bold=True)
    text_surf = overlay_font.render("Press any arrow key to start", True, WHITE)
    text_rect = text_surf.get_rect(center=(SCREEN_SIZE // 2, SCREEN_SIZE // 2))
    screen.blit(text_surf, text_rect)
    pygame.display.flip()
    pygame.event.clear()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                first_seg_dir = (0, 0)
                if len(snake) > 1:
                    first_seg_dir = (snake[1][0] - snake[0][0], snake[1][1] - snake[0][1])
                if event.key == pygame.K_UP and first_seg_dir != (0, -1): direction, game_started = (0, -1), True
                if event.key == pygame.K_DOWN and first_seg_dir != (0, 1): direction, game_started = (0, 1), True
                if event.key == pygame.K_LEFT and first_seg_dir != (-1, 0): direction, game_started = (-1, 0), True
                if event.key == pygame.K_RIGHT and first_seg_dir != (1, 0): direction, game_started = (1, 0), True

        if game_started:
            head = snake[0]
            new_head = (head[0] + direction[0], head[1] + direction[1])
            hunger -= 0.5
            thirst -= 1

            if (new_head in snake or new_head in walls or not (0 <= new_head[0] < GRID_SIZE and 0 <= new_head[1] < GRID_SIZE) or hunger <= 0 or thirst <= 0):
                # Using the yield current value properly
                earned = (len(snake) - 1) * upgrades["money_yield"]["current"]
                player_money += max(0, earned)
                show_upgrade_window(len(snake))
                return

            snake.insert(0, new_head)
            if new_head == food:
                score += 1
                hunger = MAX_HUNGER
                thirst = min(thirst + 10, MAX_THIRST)
                food = random_empty_cell(snake, walls, forbidden=water)
            elif new_head == water:
                thirst = MAX_THIRST
                water = random_empty_cell(snake, walls, forbidden=food)
            else:
                snake.pop()

        screen.fill(BLACK)
        for cell in snake: draw_cell(cell, GREEN)
        draw_cell(snake[0], DARK_GREEN); draw_cell(food, RED); draw_cell(water, BLUE)
        for wall in walls: draw_cell(wall, GRAY)
        draw_hunger_bar(hunger); draw_thirst_bar(thirst)
        score_text = font.render(f"Score: {score}", True, WHITE)
        screen.blit(score_text, (10, SCREEN_SIZE + 55))
        if not game_started: screen.blit(text_surf, text_rect)
        pygame.display.flip()
        clock.tick(FPS)

show_upgrade_window(1)
while True:
    game_loop()
