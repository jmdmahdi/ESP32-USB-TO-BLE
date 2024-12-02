# 1 "/var/folders/wf/54st2nkj1mqf0fsdthw3jnz80000gn/T/tmpv8o04irz"
#include <Arduino.h>
# 1 "/Users/rakshitbharat/hardware/ESP32-USB-TO-BLE/src/ESP32-USB-TO-BLE.ino"

#define FORCE_TEMPLATED_NOPS 

#include "ESP32-USB-Soft-Host.h"
#include "BleDevice.h"

BleDevice bleDevice;


uint8_t keyboardDevice = -1;
uint8_t mouseDevice = -1;
void USB_IfaceDesc_Detect(uint8_t usbNum, int cfgCount, int sIntfCount, void *Intf, size_t len);
void USB_Data_Handler(uint8_t usbNum, uint8_t byte_depth, uint8_t *data, uint8_t data_len);
void setup();
void loop();
#line 14 "/Users/rakshitbharat/hardware/ESP32-USB-TO-BLE/src/ESP32-USB-TO-BLE.ino"
void USB_IfaceDesc_Detect(uint8_t usbNum, int cfgCount, int sIntfCount, void *Intf, size_t len) {

  if (cfgCount == 1 && sIntfCount == 1) {
    sIntfDesc *sIntf = (sIntfDesc *)Intf;

    if (sIntf->iProto == 1) {
      keyboardDevice = usbNum;
    } else if (sIntf->iProto == 2) {
      mouseDevice = usbNum;
    }
  }
}


void USB_Data_Handler(uint8_t usbNum, uint8_t byte_depth, uint8_t *data, uint8_t data_len) {
  #ifdef DEBUG_ALL

    printf("%s data: ", usbNum == mouseDevice ? "Mouse" : "Keyboard");
    for (int k = 0; k < data_len; k++) {
      printf("0x%02x ", data[k]);
    }
    printf("\n");
  #endif


  if (data_len > 4) {
    #ifdef DEBUG_ALL
      printf("sendKeyboardReport\n");
    #endif
    bleDevice.sendKeyboardReport(data, data_len);
  } else {
    #ifdef DEBUG_ALL
      printf("sendMouseReport\n");
    #endif
    bleDevice.sendMouseReport(data, data_len);
  }
}


void setup() {

  USH.setOnIfaceDescCb(USB_IfaceDesc_Detect);

  USH.init(USB_Data_Handler);


  bleDevice.begin();
}


void loop() {
  vTaskDelete(NULL);
}