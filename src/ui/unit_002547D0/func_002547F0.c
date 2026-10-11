#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00211408(void *, s32);
void func_002117A0(void *);
s32 func_00213158(s32);
void func_00250D68(s32, void *);
struct func_002547F0_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_002547F0(struct func_002547F0_arg0 *arg0) {
    s32 sp[4];
    s32 temp_s1;
    arg0->unk10 = 0;
    func_002117A0(sp);
    temp_s1 = func_00213158(sp[0]);
    func_00211408(sp, 2);
    arg0->unk18 = arg0->unk14;
    func_00250D68(temp_s1, arg0);
}
