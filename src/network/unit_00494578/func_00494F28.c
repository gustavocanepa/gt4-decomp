#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004945C0(void *);                      /* extern */
s32 func_00494A28();                            /* extern */

struct func_00494F28_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x97C];
    s32 unk988;
};

s32 func_00494F28(struct func_00494F28_arg0 *arg0) {
    s32 temp_s0;

    func_00494A28();
    temp_s0 = ((((arg0->unk8 * 2) + arg0->unk988) * 4) + 0x1F) & ~0xF;
    func_004945C0(arg0);
    return temp_s0;
}
