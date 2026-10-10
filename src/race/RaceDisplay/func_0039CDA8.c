/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A9850(void *);                      /* extern */
s32 func_003A98A0(void *);                      /* extern */

struct func_0039CDA8_arg0 {
    char pad0[0x34];
    u8 unk34;
};

void func_0039CDA8(void *arg0, s32 arg1) {
    if (((struct func_0039CDA8_arg0 *)arg0)->unk34 == 0) {
        if (arg1 != 0) {
            func_003A9850(arg0 + 0xBC);
            return;
        }
        func_003A98A0(arg0 + 0xBC);
    }
}
