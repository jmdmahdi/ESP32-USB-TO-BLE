#!/bin/bash

# Create main directories
mkdir -p src
mkdir -p include
mkdir -p lib
mkdir -p test
mkdir -p images

# Move source files to src/
mv ESP32-USB-TO-BLE.ino src/main.cpp
mv BleDevice.cpp src/

# Move header files to include/
mv BleDevice.h include/
mv ESP32-USB-Soft-Host.h include/
mv ESP32-USBSoftHost.hpp include/
mv usb_host.h include/

# Move library files to lib/
mv usb_host.c lib/
mv ESP32-USBSoftHost.cpp lib/

# Keep configuration files in root
# - platformio.ini
# - ESP32-USB-TO-BLE.code-workspace
# - LICENSE
# - README.md

# Keep VSCode settings
# - .vscode/c_cpp_properties.json
# - .vscode/extensions.json
# - .vscode/settings.json

echo "Project structure reorganized successfully!"