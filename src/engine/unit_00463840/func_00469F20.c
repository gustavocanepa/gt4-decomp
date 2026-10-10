#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 *func_0046A050(void **, s32);                   /* extern */
s32 func_0046A070(void **, s32);                    /* extern */
void *func_0046A090(void **, s32);                  /* extern */
s32 func_0046B230(s32);                             /* extern */

struct func_00469F20_arg0 {
    s8 unk0;
    s8 unk1;
    char pad2[0x2];
    s32 unk4;
    void *unk8;
};

void func_00469F20(struct func_00469F20_arg0 *arg0, void **arg1, s32 arg2) {
    s32 *temp_v0;
    s32 temp_a0;
    void *temp_v0_2;

    if (func_0046B230(M2C_FIELD(*arg1, s32 *, 0x9C)) != 0) {
        arg0->unk4 = func_0046A070(arg1, arg2);
        arg0->unk8 = func_0046A090(arg1, arg2);
        arg0->unk0 = 1;
        arg0->unk1 = 0x40;
        return;
    }
    temp_v0 = func_0046A050(arg1, arg2);
    temp_a0 = *temp_v0;
    temp_v0_2 = temp_v0 + 1;
    arg0->unk1 = 0x28;
    arg0->unk4 = temp_a0;
    arg0->unk8 = temp_v0_2;
    arg0->unk0 = 0;
}
