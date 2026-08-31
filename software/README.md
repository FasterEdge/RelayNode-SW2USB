# RelayNode-SW2USB firmware

## Directory

- `CH552G/keil/`: CH552G Keil C51 application source integrated with the WCH CH55x USB Device/HID SDK.

Only the platform that maps cleanly to the real chip and vendor SDK is included. CH552G is an enhanced 8051 device; Keil C51 plus the official WCH CH55x SDK is the reliable path for native USB firmware.

## Behavior

- U1 pins 2/3/4/5 are CH552G P1.1/P1.2/P1.3/P1.4 and correspond to SW1/SW2/SW3/SW4.
- Inputs use internal pull-ups; an external switch closes to its paired GND terminal.
- A 25 ms debounce filter is applied.
- USB HID report ID 1 carries one data byte:
  - bit0: SW1
  - bit1: SW2
  - bit2: SW3
  - bit3: SW4
  - bit value 1 means closed/active.

## Keil C51 integration

1. Install Keil C51 and obtain the WCH CH552/CH554 SDK.
2. Create/open a CH552G project and add:
   - WCH startup file and `CH552.H`
   - WCH system/clock delay implementation (`CfgFsys`, `mDelaymS`)
   - WCH USB device core (`USBDeviceCfg`, endpoint and interrupt configuration)
   - HID descriptors and endpoint code
   - this repository's `CH552G/keil/User/main.c`
3. Implement the small adapter declared in `main.c`:

```c
void usb_hid_send_report(uint8_t report_id,
                         const uint8_t *data,
                         uint8_t length);
```

It must queue report ID 1 and the one-byte switch bitmap on the HID IN endpoint.
4. Build the `.hex` file.
5. Enter the CH552 bootloader according to the WCH bootloader procedure, connect USB-C, and flash with WCHISPTool/WCHISPStudio.

## Important hardware note

The board has no dedicated boot/reset pushbutton shown in the current BOM. If the factory-fresh chip does not enter the USB bootloader automatically, a temporary programmer/boot access method may be required. Verify the CH552G boot-entry pin and reset procedure from the exact WCH datasheet/bootloader version before mass production.
