# LogicSim

A digital logic circuit simulator built in C++ with Qt. Drag logic gates and input/output sources onto a canvas, wire them together, and watch signal state propagate through the circuit in real time.

## Aim

A practice project intended as a learning platform for young students (future engineers), to learn the basics of electronics and logic gates through hands-on, visual experimentation rather than abstract theory.

![canvas_presentation2](https://github.com/user-attachments/assets/05321547-721c-4c20-af89-cc9e026db23a)

## Features

- **Interactive circuit canvas**: drag components from a palette, drop them onto the scene, and connect ports by clicking between them
- **Live simulation**: component states update and propagate through the circuit automatically whenever a connection or input changes
- **Supported components:**
  - Inputs: VCC, GND, push button
  - Logic gates: AND, OR, NOT
  - Outputs: LED, buzzer

## Architecture

The simulation core is fully decoupled from the UI `Core/Circuit` contains no Qt dependencies at all, so the logic can be reasoned about (and tested) independently of how it's rendered.

```
Core/Circuit/
├── Components/       Component, Port, and concrete component types
│                      (gates, inputs, outputs), built via ComponentsFactory
└── Managers/          CircuitManager — owns all components, evaluates
                        circuit state, notifies observers on change

UI/
├── Controllers/        SceneEditor (canvas interaction), MainGuiContainer
├── disp/                Qt widgets, views, and .ui forms
└── Models/              Component metadata for the palette

Common/
└── Observable/IObserver  Generic observer pattern used to notify the UI
                          when circuit state changes
```

**Key design decisions:**

- **Factory pattern** (`ComponentsFactory`) creates the correct component subclass from an `ElementType` enum, keeping construction logic in one place.
- **Observer pattern** (`Observable`/`IObserver`) lets `SceneEditor` react to circuit state changes without `CircuitManager` knowing anything about the UI.
- **Circuit evaluation** repeatedly recomputes component outputs until the circuit reaches a stable state (a fixed-point iteration), so it correctly handles circuits where signal changes cascade through multiple components in one update.

## Building

### Requirements

- CMake 3.16+
- Qt 6 (or Qt 5) with the **Widgets** and **Multimedia** components
- A C++17-compatible compiler

### Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Or open `CMakeLists.txt` directly in Qt Creator and build from there.

## Project structure

| Path | Contents |
|---|---|
| `Core/Circuit/Components/` | Component base class, ports, and all concrete component types |
| `Core/Circuit/Managers/` | `CircuitManager` — the simulation engine |
| `Common/` | Shared interfaces (`Observable`, `IObserver`) |
| `UI/Controllers/` | Scene interaction and window composition |
| `UI/disp/` | Qt widgets and `.ui` form files |
| `UI/disp/Widgets/CircuitElement/` | Visual representation of each component type on the canvas |
| `Resources/` | Icons and images used by the UI |

## Roadmap

- [ ] Unit tests for `CircuitManager` and component evaluation logic
- [ ] Additional logic gates (NAND, NOR, XOR, XNOR)
- [ ] Save/load circuits to file

## License

All rights reserved.
