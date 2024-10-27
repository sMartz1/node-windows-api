# Mouse Controller Library for Windows

This is a Node.js library project that allows you to control the mouse on Windows systems. The library is written in C++ and provides two main functions: moving the mouse to an absolute position and moving the mouse relative to its current position. This library is similar to RobotJS but built from scratch to provide better understanding and customization of cursor control.

## Features

- **Move the mouse to an absolute position**: Moves the mouse cursor to the given `(x, y)` coordinates.
- **Move the mouse relatively**: Moves the mouse cursor from its current position by adding `(deltaX, deltaY)` offsets.

## Installation

To compile this library, you need to have `node-gyp` and a suitable development environment set up on your system.

### Steps to Install

1. **Clone the repository to your local system**:

    ```sh
    git clone <REPOSITORY_URL>
    ```

2. **Navigate to the project directory**:

    ```sh
    cd <REPOSITORY_NAME>
    ```

3. **Install the development dependencies**:

    ```sh
    npm install -g node-gyp
    ```

4. **Configure and compile the project using `node-gyp`**:

    ```sh
    node-gyp configure build
    ```

5. **Import the compiled library**:

    Once compiled, you can import the library into your Node.js project.

## Usage

To use the library, import it in your JavaScript code and call the provided functions to control the mouse cursor.

### Example Usage

```js
const mouseController = require('./build/Release/mouse_controller');

// Move the mouse to the absolute position (x: 100, y: 150)
mouseController.moveMouse(100, 150);

// Move the mouse relatively (deltaX: 50, deltaY: -30)
mouseController.moveMouseRelative(50, -30);
```

## Requirements

- **Node.js**: v12 or higher
- **Operating System**: Windows
- **Compiler**: Compatible with `node-gyp` (e.g., Visual Studio)

