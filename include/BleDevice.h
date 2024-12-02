#ifndef ESP32_BLE_Device_H
#define ESP32_BLE_Device_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include "BLEHIDDevice.h"
#include "BLECharacteristic.h"


class BleDevice : public BLEServerCallbacks, public BLECharacteristicCallbacks {
private:
  BLEHIDDevice* hid;
  BLECharacteristic* inputMouse;
  BLECharacteristic* inputKeyboard;
  BLECharacteristic* outputKeyboard;
  BLECharacteristic* inputMediaKeys;
  BLEAdvertising* advertising;
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
  virtual void onConnect(BLEServer* pServer) override;
  virtual void onDisconnect(BLEServer* pServer) override;
};

#endif  // CONFIG_BT_ENABLED
#endif  // ESP32_BLE_Device_H
