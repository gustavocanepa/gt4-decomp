#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003285A8(s32);
void func_003285F8(s32);
struct func_002F48A0_temp_s1 {
    u8 pad0[0x4];
    s32 unk4;
};

void func_002F48A0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s2;
    struct func_002F48A0_temp_s1 *temp_s1;
    temp_s1 = (void *)(arg0 + 0x2C);
    temp_s2 = arg1 * 4;
    func_003285F8(*(s32 *)(temp_s1->unk4 + temp_s2));
    func_003285A8(arg2);
    *(s32 *)(temp_s1->unk4 + temp_s2) = arg2;
}
