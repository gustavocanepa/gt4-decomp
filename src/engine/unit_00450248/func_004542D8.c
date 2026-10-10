#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004591C0(s32, s32, s32, s32, s32, void *); /* extern */

struct func_004542D8_temp_a5 {
    char pad0[0x10];
    s32 unk10;
};

void func_004542D8(void **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct func_004542D8_temp_a5 *temp_a5;

    temp_a5 = *arg0;
    func_004591C0(temp_a5->unk10, arg4, arg1, arg2, arg3, temp_a5);
}
