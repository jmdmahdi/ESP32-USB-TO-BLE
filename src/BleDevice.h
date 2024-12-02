#pragma once

#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include <NimBLEHIDDevice.h>

class BleDevice : public NimBLEServerCallbacks, public NimBLECharacteristicCallbacks {
private:
    NimBLEHIDDevice* hid;
    NimBLECharacteristic* inputMouse;
    NimBLECharacteristic* inputKeyboard;
    NimBLECharacteristic* outputKeyboard;
    NimBLECharacteristic* inputMediaKeys;
    NimBLEAdvertising* advertising;
    std::string deviceName;
    std::string deviceManufacturer;
    bool connected = false;

public:
    BleDevice(std::string deviceName = "ESP32 Mouse/Keyboard", std::string deviceManufacturer = "Espressif");
    void begin(void);
    void end(void){};
    void sendKeyboardReport(uint8_t* data, uint8_t len);
    void sendMouseReport(uint8_t* data, uint8_t len);
    bool isConnected(void);

protected:
    virtual void onConnect(NimBLEServer* pServer) override;
    virtual void onDisconnect(NimBLEServer* pServer) override;
}; 