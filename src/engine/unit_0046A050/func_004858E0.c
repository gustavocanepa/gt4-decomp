#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00574D78();                            /* extern */

extern char D_00688B40[];
struct func_004858E0_arg0 {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
};

s32 func_004858E0(struct func_004858E0_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk3C = (s32)D_00688B40;
    func_00574D78();
    arg0->unk30 = arg1;
    arg0->unk34 = arg2;
    arg0->unk38 = 0;
}
