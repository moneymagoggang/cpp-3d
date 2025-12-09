# cpp-3d

## Prerequisites

### macOS
```bash
brew install cmake sfml
```

### Windows
Install via vcpkg:
```cmd
vcpkg install sfml:x64-windows
```

Or download SFML from https://www.sfml-dev.org/download.php

### Linux
```bash
sudo apt install cmake libsfml-dev
```

## Building

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running
```bash
./cpp-3d
```