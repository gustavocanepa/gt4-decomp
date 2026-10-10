#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00500ED8_arg0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

void func_00500ED8(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    func_005A6AB0(arg0 + 0x14, arg1, 0x10);
    ((struct func_00500ED8_arg0 *)arg0)->unk2C = arg3;
    ((struct func_00500ED8_arg0 *)arg0)->unk24 = arg2;
    ((struct func_00500ED8_arg0 *)arg0)->unk28 = -1;
}
