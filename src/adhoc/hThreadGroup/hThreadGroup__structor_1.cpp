#include "gt4/hThreadGroup.h"
typedef int s32;

extern void *hThreadGroup__vtable;
extern "C" void func_005F1AE0(void *);
extern "C" void *func_005F1BC0(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void func_00318538(void *, s32);
extern "C" void hObject__structor_2(void *, s32);
static inline void member_0(char *m) {
    func_005F1AE0(m);
    void *p0 = *(void **)(m + 0x4);
    void *r1 = func_005F1BC0();
    func_00326798(p0, 0xc, 0x4, *(void **)(r1));
}

extern "C" void hThreadGroup__structor_1(void *arg0, s32 arg1) {
    ((struct hThreadGroup *)arg0)->unk4 = &hThreadGroup__vtable;
    member_0((char *)arg0 + 0x14);
    func_00318538((char *)arg0 + 0x10, 0x2);
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x1c, 0x4, "RefCounter");
    }
}
