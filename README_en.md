<div align="center">
<img src="https://avatars.githubusercontent.com/u/245985800?s=200&v=4" style="width:100px;" width="100"/>
<h2>RelayNode - SW2USB</h2>
<h3>Serial-to-USB relay node (JLC EDA Pro hardware project)</h3>
</div>

### 1. Introduction

**RelayNode-SW2USB** is a hardware node in the FasterEdge ecosystem: a **serial-to-USB relay control board** built around a **PY32F003** MCU. The hardware is drawn in **JLCEDA Pro** (.eprj2) and pairs with the [MCU-PY32F003](https://github.com/FasterEdge/MCU-PY32F003) firmware as the actuator end of FasterEdge Modbus/OneKey capabilities.

- ✅ JLCEDA Pro project (`sw2usb_main.eprj2`), open the single file
- ✅ Main MCU **PY32F003** (Cortex-M0+, one of the FasterEdge MCU platforms)
- ✅ Relay output + serial/USB control path
- ✅ Minimal BOM (single-chip design)

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
3. Check BOM (`BOM.txt`): PY32F003 ×1, add relays/connectors as needed
4. Firmware: flash the [MCU-PY32F003](https://github.com/FasterEdge/MCU-PY32F003) Keil/PlatformIO project, interact over serial 115200

**Serial command examples (with MCU-PY32F003 firmware):**

```
ability_ModbusAbility set_unit_id 3
ability_ModbusAbility write_holding 0,1      # relay on
ability_ModbusAbility write_holding 0,0      # relay off
ability_GpioAbility write 10,1
```

### 4. Version

- **1.0.20260829** (in sync with all FasterEdge platforms)

### 5. Sibling Projects

- **[FasterEdge MCU - PY32F003](https://github.com/FasterEdge/MCU-PY32F003)**: main MCU firmware (Keil / PlatformIO)
- **[FasterEdge MCU - CH32V003](https://github.com/FasterEdge/MCU-CH32V003)**: alternative MCU (RISC-V)
- **[FasterEdge](https://github.com/FasterEdge/FasterEdge)**: framework main repo
