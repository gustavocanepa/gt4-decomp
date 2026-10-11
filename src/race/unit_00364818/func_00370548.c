#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005F5040(void *, void *);              /* extern */

struct func_00370548_arg0 {
    char pad0[0x38];
    s32 unk38;
    char pad3C[0x4];
    s32 unk40;
};

void func_00370548(void *arg0, void *arg1, s32 arg2) {
    void *temp_s1;

    temp_s1 = arg0 + 0x34;
    func_005F5040(arg1, temp_s1);
    ((struct func_00370548_arg0 *)arg0)->unk38 = 0;
    func_005F5040(temp_s1, arg0 + 0x28);
    ((struct func_00370548_arg0 *)arg0)->unk40 = arg2;
}
