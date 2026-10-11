#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00565698(void *);
s32 func_005539D8(void *);                          /* extern */

struct func_00565A78_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    char pad2C[0x30];
    s32 unk5C;
    s32 unk60;
};

void func_00565A78(struct func_00565A78_arg0 *arg0) {
    func_005A48D8(arg0, 0, 8);
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk5C = func_005539D8(arg0);
    arg0->unk60 = func_00565698(arg0);
}
