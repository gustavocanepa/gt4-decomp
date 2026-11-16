#include "types.h"

extern char mColorWindow__tf[];
extern char hObject__tf[];
extern "C" void mComposite__deepCopy(void);
extern "C" void *__dynamic_cast_2(void *, void *, s32, void *, void *, void *);
extern "C" void func_005E49B0(void *, void *);

struct VEntry {
    s16 delta;
    s16 index;
    void *ptr;
};

struct mColorWindow {
    char pad0[4];
    VEntry *vtbl;
    char pad8[0xA8];
    char unkB0[0x10];
    s32 unkC0;
};

extern "C" void mColorWindow__deepCopy(mColorWindow *arg0, mColorWindow *arg1) {
    mColorWindow *v_s1 = 0;
    mComposite__deepCopy();
    if (arg1 != 0) {
        VEntry *e = arg1->vtbl;
        v_s1 = (mColorWindow *)__dynamic_cast_2(e->ptr, &mColorWindow__tf, 0, (char *)arg1 + e->delta, &hObject__tf, arg1);
    }
    if (v_s1 != 0) {
        if (&arg0->unkB0[0] != &v_s1->unkB0[0]) {
            func_005E49B0(arg0->unkB0, v_s1->unkB0);
        }
        arg0->unkC0 = v_s1->unkC0;
    }
}
