/* FasterEdge 开源项目
 * GitHub: https://github.com/FasterEdge
 * Gitee:  https://gitee.com/FasterEdge
 */
#include <stdint.h>
#include "CH552.H"
#include "Debug.H"

/* USB HID transport is supplied by the WCH CH55x USB device library.
 * The hook must send report ID 1 followed by one byte of switch bits. */
extern void usb_hid_send_report(uint8_t report_id, const uint8_t *data, uint8_t length);

static uint8_t stable_state;
static uint8_t sampled_state;
static uint8_t debounce_ticks[4];

static uint8_t read_inputs(void) {
    uint8_t value = 0;
    if (!P1_1) value |= 0x01;
    if (!P1_2) value |= 0x02;
    if (!P1_3) value |= 0x04;
    if (!P1_4) value |= 0x08;
    return value;
}

static void send_switch_report(uint8_t value) {
    uint8_t report = value;
    usb_hid_send_report(1, &report, 1);
}

void main(void) {
    uint8_t i;
    CfgFsys();
    /* 四路开关输入引脚 P1.1-P1.4 配置为输入(DIR_PU 位=0 时内部上拉有效),
     * 开关接 GND 闭合时读低。旧实现 |= 0x1E 把输入脚置为输出: 复位后推挽
     * 高电平, read_inputs() 恒读到高致开关永远读不到闭合(功能失效), 且开关
     * 闭合到 GND 时与推挽高电平形成灌电流短路(引脚/开关损坏风险)。 */
    P1_DIR_PU &= (uint8_t)~0x1E;
    USBDeviceCfg();
    USBDeviceEndpCfg();
    USBDeviceIntCfg();
    USBDeviceCtrl(0x00);

    stable_state = read_inputs();
    sampled_state = stable_state;
    send_switch_report(stable_state);

    while (1) {
        uint8_t current = read_inputs();
        for (i = 0; i < 4; ++i) {
            uint8_t mask = (uint8_t)(1U << i);
            if ((current & mask) != (sampled_state & mask)) {
                sampled_state ^= mask;
                debounce_ticks[i] = 0;
            } else if (debounce_ticks[i] < 5) {
                ++debounce_ticks[i];
            } else if ((sampled_state & mask) != (stable_state & mask)) {
                stable_state = (stable_state & (uint8_t)~mask) | (sampled_state & mask);
                send_switch_report(stable_state);
            }
        }
        mDelaymS(5);
    }
}
