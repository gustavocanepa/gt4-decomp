#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u8 *func_0038D0B8(void);
s32 NormalCarGeometry__IsManualShift(void) {
    u8 c = func_0038D0B8()[2];
    if (c == 0 || c == 0xF || c == 0x10 || c == 0x11 || c == 0x20) {
        return 0;
    }
    return 1;
}
