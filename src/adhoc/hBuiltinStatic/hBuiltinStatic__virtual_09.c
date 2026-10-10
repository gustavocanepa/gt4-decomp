#include "types.h"
#include "gt4/hBuiltinStatic.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00309378(void *, s32);
void *func_0030BB18(void *);
void hBuiltinStatic__virtual_09(struct hBuiltinStatic *arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    func_0030BB18(sp);
    arg0->unk10_fn(sp, 1, arg2);
    func_00309378(sp, 2);
}
