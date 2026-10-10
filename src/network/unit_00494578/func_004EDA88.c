/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00576AD8(s32, s32);                /* extern */
s32 func_00578168(void *, s32, s32, void *, s32); /* extern */
s32 func_00578500(s32);                         /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */
s32 func_005A6AB0(void *, s32, s32);        /* extern */

struct func_004EDA88_arg0 {
    s32 unk0;
    char pad4[0x3C];
    void *unk40;
    char pad44[0xC];
    s32 unk50;
};

s32 func_004EDA88(struct func_004EDA88_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00576AD8(arg0->unk50, 0x1340);
    func_00578500(arg0->unk0);
    func_005A48D8(arg0->unk40, 0, 0x20C);
    M2C_FIELD(arg0->unk40, s32 *, 0) = (s32) arg0->unk50;
    M2C_FIELD(arg0->unk40, s32 *, 4) = arg1;
    func_005A6AB0(arg0->unk40 + 0x10, arg2, 0xB);
    func_005A6AB0(arg0->unk40 + 0x1C, arg3, 0xFF);
    func_00578168(arg0, 5, 0, arg0->unk40, 0x40);
    return M2C_FIELD(arg0->unk40, s32 *, 0);
}
