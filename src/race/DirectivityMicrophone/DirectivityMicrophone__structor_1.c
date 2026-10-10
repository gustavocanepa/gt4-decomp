#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char DirectivityMicrophone__vtable[];
struct DirectivityMicrophone {
    s32 unk0;
    char unk_4[0x4];
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    void * unk1C;
    s32 unk20;
    f32 unk24;
};
s32 func_005C1628(struct DirectivityMicrophone *); /* extern */

void DirectivityMicrophone__structor_1(struct DirectivityMicrophone *arg0, s32 arg1) {
    arg0->unk1C = (void *)(s32)DirectivityMicrophone__vtable;
    func_0039A4F8(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
