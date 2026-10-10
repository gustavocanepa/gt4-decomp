#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00455598(void *, s32, s32);        /* extern */
s32 func_004567C0(s32);                     /* extern */

struct func_003E1880_arg0 {
    char pad0[0x570];
    s32 unk570;
    char pad574[0x4];
    void *unk578;
};
struct func_003E1880_temp_a0 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 func_003E1880(struct func_003E1880_arg0 *arg0) {
    struct func_003E1880_temp_a0 *temp_a0;

    if ((arg0->unk578 != NULL) && (arg0->unk570 > 0)) {
        func_004567C0(1);
        temp_a0 = arg0->unk578;
        func_00455598(temp_a0, 0, temp_a0->unk7C);
    }
}
