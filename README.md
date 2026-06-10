## Build and Run Configuration

This project is built using VS Code and GCC/MinGW. Follow these steps to compile and run the game on Windows.

### 1. Configure Compiler Paths
This workspace comes with a pre-configured `.vscode/tasks.json` file. Open it and ensure that the paths for `-I` (Include directory) and `-L` (Lib directory) match where you have SFML installed on your local system:
* `"C:/SFML-2.6.2/include"`  
* `"C:/SFML-2.6.2/lib"`
(path can vary, it depends on where you downloded sfml libraries)

### 2. Building the Project
1. Open the project folder in VS Code.
2. Press `Ctrl + Shift + B` to trigger the compilation task.
3. This will compile all `.cpp` files and generate an executable named `main.exe` in your workspace directory.

### 3. Required DLL Files (CRITICAL)
Before you double-click `main.exe` to play, you **must copy the required SFML DLL files** into the exact same folder where your `main.exe` is located. If you skip this, the game will fail to launch.

Go to your local SFML folder (`SFML-2.6.2/bin/`) and copy the following **3 DLL files** into your game project folder:
* `sfml-graphics-2.dll`
* `sfml-window-2.dll`
* `sfml-system-2.dll`

*(Note: If you are compiling a Debug build, look for the files ending in `-d.dll` instead, such as `sfml-graphics-d-2.dll`)*.

### 4. Run the Game
Once the `.dll` files are sitting right next to your `main.exe` and your font asset path is correct, simply double-click `main.exe` to launch the game!

| ![Gameplay](gameplay.png) | ![Game Over](gameover.png) |
