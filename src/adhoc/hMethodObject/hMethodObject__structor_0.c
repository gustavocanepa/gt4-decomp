#include "types.h"
#include "gt4/hMethodObject.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char hMethodObject__vtable[];
void func_003038B0(void *, s32 *);
void func_00309360(void *, s32);
s32 hObject__structor_0(void *);
void hMethodObject__structor_0(void *arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    hObject__structor_0(arg0);
    ((struct hMethodObject *)arg0)->unk4 = (s32)hMethodObject__vtable;
    func_00309360((s8 *)arg0 + 0x10, arg1);
    sp[0] = arg2;
    func_003038B0((s8 *)arg0 + 0x14, sp);
}
