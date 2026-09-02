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
    P1_MOD_OC &= (uint8_t)~0x1E;
    P1_DIR_PU |= 0x1E;
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
