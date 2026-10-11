/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576AD8(s32, s32);                /* extern */
s32 func_00578168(void *, s32, s32, void *, s32); /* extern */
s32 func_00578500(s32);                         /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_004ED410_arg0_unk40 {
    s32 unk0;
};
struct func_004ED410_arg0 {
    s32 unk0;
    char pad4[0x3C];
    struct func_004ED410_arg0_unk40 *unk40;
    char pad44[0x1C];
    s32 unk60;
};
struct func_004ED410_temp_v1 {
    s32 unk0;
    s32 unk4;
};

s32 func_004ED410(struct func_004ED410_arg0 *arg0, s32 arg1) {
    struct func_004ED410_temp_v1 *temp_v1;

    func_00576AD8(arg1, 0x1340);
    func_00578500(arg0->unk0);
    func_005A48D8(arg0->unk40, 0, 0x20C);
    arg0->unk40->unk0 = arg1;
    func_00578168(arg0, 3, 0, arg0->unk40, 0x40);
    temp_v1 = arg0->unk40;
    arg0->unk60 = (s32) temp_v1->unk4;
    return temp_v1->unk0;
}
