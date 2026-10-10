#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00344888(void *, f32);
s32 func_00359F50(void *);
f32 func_0035A008(f32, f32);                        /* extern */
f32 func_0035A540(void *, s32);                 /* extern */

struct func_0035A3C0_arg0_unk10 {
    char pad0[0x32];
    u8 unk32;
};
struct func_0035A3C0_arg0 {
    char pad0[0x10];
    struct func_0035A3C0_arg0_unk10 *unk10;
    char pad14[0x558];
    f32 unk56C;
};

struct func_0035A3C0_temp_s0 {
    char pad0[0x30];
    f32 unk30;
};

f32 func_0035A3C0(struct func_0035A3C0_arg0 *arg0, f32 fparg0) {
    f32 temp_f20;
    s32 temp_s0;

    if (arg0->unk10->unk32 == 6) {
        temp_s0 = func_00359F50(arg0);
        temp_f20 = func_0035A008(((struct func_0035A3C0_temp_s0 *)temp_s0)->unk30, func_00344888(arg0, fparg0));
        return func_0035A540(arg0, 1) / temp_f20;
    }
    return arg0->unk56C;
}
