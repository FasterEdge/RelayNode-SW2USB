<div align="center">
<img src="https://avatars.githubusercontent.com/u/245985800?s=200&v=4" style="width:100px;" width="100"/>
<h2>RelayNode - SW2USB</h2>
<h3>CH552G native-USB four-channel switch input node (JLCEDA Pro hardware project)</h3>
</div>

### 1. Introduction

**RelayNode-SW2USB** is a FasterEdge hardware input node built around the **CH552G** MCU. It communicates through the MCU's native USB D+/D- interface and provides **four switch inputs (SW1-SW4)**. The hardware is designed in **JLCEDA Pro** (.eprj2).

- ✅ JLCEDA Pro project (`sw2usb_main.eprj2`), open the single file
- ✅ **CH552G** MCU (enhanced 8051 with native USB device interface)
- ✅ USB-C power and data, with independent 5.1kΩ CC1/CC2 pull-down resistors
- ✅ Four switch input terminals plus four paired ground terminals
- ✅ Compact 15-component BOM

### 2. Directory Layout

```
RelayNode-SW2USB/
├── sw2usb_main.eprj2           # JLCEDA Pro project file (schematic + PCB)
├── sw2usb_main_backup/         # EDA auto backups (.epro2 snapshots)
├── hardware/                   # hardware exports/backups
├── software/                   # firmware placeholder (see MCU-PY32F003)
├── BOM.txt                     # bill of materials
├── LICENSE                     # Apache-2.0
└── README.md
```

### 3. Usage

1. Install **JLCEDA Professional** (LCEDA Pro)
2. Open the `sw2usb_main.eprj2` project (schematic / PCB included)
3. Check `BOM.txt`: it lists the CH552G MCU, USB-C connector, and all four switch/ground terminals
4. Build and flash suitable CH552G USB HID, USB CDC, or vendor-specific device firmware; input pull-up behavior and the USB protocol are firmware-defined

**Hardware interfaces:**

- J1: USB-C (VBUS, D+, D-, CC1, CC2, GND, SHLD)
- J2-J5: SW1-SW4
- J6-J9: paired ground terminals
- R1/R2: 5.1kΩ CC1/CC2 pull-downs
- C1: VBUS input filtering; C2/C3: 3V3/VBUS decoupling

### 4. Version

- **1.0.20260831** (in sync with all FasterEdge platforms)

### 5. Sibling Projects

- **[FasterEdge MCU - PY32F003](https://github.com/FasterEdge/MCU-PY32F003)**: main MCU firmware (Keil / PlatformIO)
- **[FasterEdge MCU - CH32V003](https://github.com/FasterEdge/MCU-CH32V003)**: alternative MCU (RISC-V)
- **[FasterEdge](https://github.com/FasterEdge/FasterEdge)**: framework main repo
