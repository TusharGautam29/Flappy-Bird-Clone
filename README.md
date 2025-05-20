# 🐤 Flappy Bird Clone – Built with HyperReal Game Engine

A Flappy Bird-style 2D side-scroller built using the **HyperReal Game Engine**, designed for simplicity and power. This game replicates the addictive tap/hold-to-fly gameplay, adds particle effects, a dynamic camera, ImGui controls, and uses a modular system built from scratch.

---

## 🎮 Features

- 🚀 Flappy Bird mechanics: tap/hold `Space` to fly, dodge incoming pillars
- 🧠 Modular architecture: `GameLayer`, `Player`, and `Level` systems
- 🔥 Particle effects for engine flames and smoke trails
- 🎯 Dynamic camera follows the player smoothly
- 🛠️ ImGui panel for real-time gameplay tuning
- 📈 Score tracking and Game Over state

---

## 🧩 Game Architecture

### 📂 `GameLayer`
- Main layer of the game.
- Manages state: Main Menu, Play, Game Over.
- Handles ImGui UI and user input.
- Delegates update and render to `Player` and `Level`.

### 🚀 `Player`
- Handles player physics (gravity, jump force).
- Emits smoke and engine flame particles.
- Renders a rotating ship sprite.
- Exposes ImGui panel for real-time tuning of:
  - Engine power
  - Gravity

### 🧱 `Level`
- Spawns pillars at set intervals.
- Scrolls pillars across the screen.
- Detects collisions with player.
- Manages scoring.

---

## 🖼️ Visuals

- **Renderer2D** draws all objects (ship, background, pillars).
- **ParticleSystem** used for:
  - Engine flame on jump
  - Smoke trail when flying
- **Textures**:
  - `assets/textures/Ship.png` for the player ship

---

## 🧪 Real-Time Tweaking (ImGui)

Adjust gameplay physics live during runtime:

- `Engine Power`: boost strength when pressing space
- `Gravity`: fall speed over time

This is useful for fine-tuning feel and responsiveness.

---
