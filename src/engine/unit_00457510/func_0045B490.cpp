#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045AFC8(void *, s32);             /* extern */

struct func_0045B490_arg0 {
    char pad0[0x4];
    s32 unk4;
};
struct func_0045B490_arg1 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_0045B490(void *arg0, void *arg1) {
    ((struct func_0045B490_arg0 *)arg0)->unk4 = (s32) (((struct func_0045B490_arg1 *)arg1)->unk8 - ((struct func_0045B490_arg1 *)arg1)->unk0);
    func_0045AFC8(arg1, 0);
    func_0045AFC8(arg1, 0);
}
