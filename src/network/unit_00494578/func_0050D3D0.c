#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0064A358[];
struct func_0050D3D0_arg0 {
    char pad0[0x10];
    s8 unk10;
};
struct func_0050D3D0_arg2 {
    char pad0[0x14];
    s8 unk14;
};

s32 func_0050D3D0(struct func_0050D3D0_arg0 *arg0, s32 arg1, struct func_0050D3D0_arg2 *arg2) {
    s32 temp_v1;

    arg0->unk10 = 0;
    arg2->unk14 = 0;
    func_005123D8((s32) arg0, *(s32 *)(s32)D_0064A358, arg1, (s32) arg2);
    temp_v1 = *(s32 *)(s32)D_0064A358;
    if (temp_v1 >= 0x3E7) {
        *(s32 *)(s32)D_0064A358 = 0;
        return 0;
    }
    *(s32 *)(s32)D_0064A358 = temp_v1 + 1;
    return 0;
}
