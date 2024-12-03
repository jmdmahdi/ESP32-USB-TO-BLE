# ESP32 USB Host to BLE Keyboard - Issue Analysis

## Keyboard Specifications
- Product: SINO WEALTH Gaming Keyboard
- VID: 0x258a
- PID: 0x002a
- Speed: Full-speed (12 Mb/s)
- Current Required: 500mA

## What Went Wrong

### 1. Signal Level Issues
- ESP32 internal pull-up (~45K ohm) too weak for USB signaling
- USB requires specific resistance values:
  * D+ needs 1.5K ohm pull-up for full-speed detection
  * D- needs 15K ohm pull-down for proper signaling
- Current setup has incorrect signal levels preventing device detection

### 2. Power Requirements
- Mechanical keyboard needs 500mA
- ESP32 USB host might not provide enough power
- Unstable power can prevent proper enumeration

### 3. Speed Detection Failure
- Without proper 1.5K pull-up on D+:
  * ESP32 can't detect full-speed device
  * Keyboard speed negotiation fails
  * Device remains undetected

### 4. Signal Integrity
- Long wires or poor connections
- Missing proper pull-up/down resistors
- Incorrect voltage levels on D+/D-

## Why It Didn't Work

1. **Device Detection**
   - ESP32 couldn't properly detect keyboard because:
     * Missing 1.5K ohm pull-up on D+
     * Missing 15K ohm pull-down on D-
     * Internal resistors too weak for USB spec

2. **Power Issues**
   - Mechanical keyboard needs stable 500mA
   - USB power must be properly supplied

3. **Signal Requirements**
   - USB full-speed devices need specific voltage levels
   - Internal pull-up/down can't meet USB specifications
   - Signal timing affected by incorrect resistance values

## Required Fixes

1. **Add External Resistors**
   ```
   D+ (GPIO 16) ----[1.5K ohm]---- 3.3V
   D- (GPIO 17) ----[15K ohm]----- GND
   ```

2. **Power Supply**
   - Ensure stable 5V supply
   - Capable of providing 500mA

3. **Clean Connections**
   - Short, direct wires
   - Proper ground connection
   - Good quality USB socket

## Expected Behavior After Fix
1. ESP32 detects keyboard connection
2. Full-speed (12 Mb/s) negotiation succeeds
3. Keyboard enumeration completes
4. Device appears as BLE keyboard
5. Keystrokes transmitted properly
