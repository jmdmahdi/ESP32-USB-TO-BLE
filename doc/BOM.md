# Bill of Materials (BOM)

## Core Components

1. ESP32-WROOM-32 Development Board

   - Quantity: 1
   - Notes: Any ESP32 development board with accessible GPIO pins

2. USB Type-A Female Socket/Connector

   - Quantity: 2 (for keyboard and mouse)
   - Notes: Standard USB Type-A Female PCB mount socket

3. Resistors
   - 1.5K ohm (1,500 ohm) resistors
     - Quantity: 2 (one for each USB port)
     - Color code: Brown-Green-Red-Gold
   - 15K ohm (15,000 ohm) resistors
     - Quantity: 2 (one for each USB port)
     - Color code: Brown-Green-Orange-Gold

## Power Supply Components

1. USB Power Supply Module

   - Quantity: 1
   - Type: 5V/2A output
   - Notes: To provide stable power for USB devices

2. Power Distribution
   - Breadboard power distribution board OR
   - DC barrel jack to terminal block adapter
   - Notes: For clean power distribution

## Connection Components

1. Breadboard

   - Quantity: 1
   - Type: Standard 830 point breadboard
   - Notes: For prototyping and connections

2. Jumper Wires
   - Male to Male: 20 pieces
   - Male to Female: 10 pieces
   - Notes: Various colors for easy identification

## Optional but Recommended

1. Logic Level Analyzer

   - Quantity: 1
   - Notes: For debugging USB signals

2. Multimeter

   - Quantity: 1
   - Notes: For testing connections and resistor values

3. Heat Shrink Tubing

   - Various sizes
   - Notes: For insulating connections

4. Capacitors
   - 100nF (0.1µF) ceramic capacitors
     - Quantity: 6 total
       - 2 for USB Port 1 (one each for D+ and D- to GND)
       - 2 for USB Port 2 (one each for D+ and D- to GND)
       - 2 for power filtering (one for each USB port VCC to GND)
   - Notes: Ceramic capacitors recommended for better high-frequency filtering

## Pin Connections Reference

1. USB Port 1 (Keyboard)

   - D+ → GPIO 16
   - D- → GPIO 17
   - 1.5K ohm to 3.3V on D+
   - 15K ohm to GND on D-

2. USB Port 2 (Mouse)
   - D+ → GPIO 22
   - D- → GPIO 23
   - 1.5K ohm to 3.3V on D+
   - 15K ohm to GND on D-

## Notes

- All resistors should be 1/4 watt rating
- Use good quality USB connectors for reliability
- Ceramic capacitors are preferred over electrolytic for this application
- Mount capacitors as close as possible to the USB connectors
- Keep wire lengths as short as possible
