#include "types.h"
#include "gt4/hFunctionObject.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char hFunctionObject__vtable[];
void func_002FA8A0(void *, s32 *);
s32 hObject__structor_0(void *);
void hFunctionObject__structor_0(void *arg0, s32 arg1) {
    s32 sp[4];
    hObject__structor_0(arg0);
    ((struct hFunctionObject *)arg0)->unk4 = (s32)hFunctionObject__vtable;
    sp[0] = arg1;
    func_002FA8A0((s8 *)arg0 + 0x10, sp);
}
