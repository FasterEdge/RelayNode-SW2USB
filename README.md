<div align="center">
<img src="https://avatars.githubusercontent.com/u/245985800?s=200&v=4" style="width:100px;" width="100"/>
<h2>RelayNode - SW2USB</h2>
<h3>CH552G 原生 USB 四路开关输入节点（嘉立创 EDA 专业版硬件工程）</h3>
</div>

### 一、简介

**RelayNode-SW2USB** 是 FasterEdge 生态的硬件输入节点：以 **CH552G** 为控制核心，通过芯片原生 USB D+/D- 与主机通信，并提供 **4 路开关输入（SW1-SW4）**。硬件工程使用**嘉立创 EDA 专业版**（.eprj2）绘制。

- ✅ 嘉立创 EDA 专业版工程（`hardware/sw2usb_main.eprj2`），单文件可打开
- ✅ 主控 **CH552G**（增强型 8051、原生 USB 设备接口）
- ✅ USB-C 供电与通信，CC1/CC2 各使用 5.1kΩ 下拉
- ✅ 4 路开关输入 + 4 路配对 GND 端子
- ✅ 精简 BOM：15 个器件

### 二、目录结构

```
RelayNode-SW2USB/
├── hardware/                   # 嘉立创 EDA 专业版工程（.eprj2）与硬件相关文件
├── firmware/                   # CH552G Keil C51 USB HID 固件与烧录说明
├── BOM.txt                     # 元器件清单
├── LICENSE                     # Apache-2.0
└── README.md
```

### 三、使用说明

1. 下载安装**嘉立创 EDA 专业版**（立创EDA专业版）
2. 打开 `hardware/sw2usb_main.eprj2` 工程（原理图 / PCB 均已绘制）
3. 查看 `BOM.txt`：主控为 CH552G，USB-C 接口与 4 路开关/GND 端子均已列出
4. 按 `firmware/README.md` 使用 Keil C51 + WCH CH55x SDK 编译并烧录 USB HID 固件；SW1-SW4 以一字节位图上报

**硬件接口：**

- J1：USB-C（VBUS、D+、D-、CC1、CC2、GND、SHLD）
- J2-J5：SW1-SW4
- J6-J9：对应 GND
- R1/R2：CC1/CC2 5.1kΩ 下拉
- C1：VBUS 输入滤波；C2/C3：3V3/VBUS 去耦

### 四、版本

- **1.0.20260831**（与 FasterEdge 各平台版本同步）

### 五、姊妹项目

- **[FasterEdge MCU - PY32F003](https://github.com/FasterEdge/MCU-PY32F003)**：本板主控固件（Keil / PlatformIO）
- **[FasterEdge MCU - CH32V003](https://github.com/FasterEdge/MCU-CH32V003)**：可替代主控（RISC-V）
- **[FasterEdge](https://github.com/FasterEdge/FasterEdge)**：框架主仓库
