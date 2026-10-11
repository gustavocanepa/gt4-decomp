/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 AutomaticFader__fadein(void *);                      /* extern */
s32 AutomaticFader__fadeout(void *);                      /* extern */

struct func_0039CDA8_arg0 {
    char pad0[0x34];
    u8 unk34;
};

void func_0039CDA8(void *arg0, s32 arg1) {
    if (((struct func_0039CDA8_arg0 *)arg0)->unk34 == 0) {
        if (arg1 != 0) {
            AutomaticFader__fadein(arg0 + 0xBC);
            return;
        }
        AutomaticFader__fadeout(arg0 + 0xBC);
    }
}
