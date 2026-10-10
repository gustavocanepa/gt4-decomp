#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A4BF8(s32, s32, s32, s32);  /* extern */

extern char D_005750F0[];
struct func_00575A40_arg0 {
    char pad0[0x48];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
};

s32 func_00575A40(struct func_00575A40_arg0 *arg0) {
    if (arg0->unk48 != 0) {
        arg0->unk48 = 0;
        func_005A4BF8(arg0->unk4C, arg0->unk50, 8, (s32)D_005750F0);
    }
}
