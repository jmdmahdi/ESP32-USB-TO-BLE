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
    uint8_t ledStatus = 0;

public:
    BleDevice(std::string deviceName = "ESP32 Mouse/Keyboard", std::string deviceManufacturer = "Espressif");
    void begin(void);
    void end(void){};
    void sendKeyboardReport(uint8_t* data, uint8_t len);
    void sendMouseReport(uint8_t* data, uint8_t len);
    bool isConnected(void);
    uint8_t getLedStatus() { return ledStatus; }
    bool isNumLockOn() { return ledStatus & 0x01; }
    bool isCapsLockOn() { return ledStatus & 0x02; }
    bool isScrollLockOn() { return ledStatus & 0x04; }

protected:
    virtual void onConnect(NimBLEServer* pServer) override;
    virtual void onDisconnect(NimBLEServer* pServer) override;
    void onWrite(NimBLECharacteristic* pCharacteristic) override;
}; 