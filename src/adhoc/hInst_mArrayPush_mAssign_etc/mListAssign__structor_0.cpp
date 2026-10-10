#include "gt4/mListAssign.h"
typedef int s32;

extern void *mListAssign__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mListAssign__structor_0(struct mListAssign *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mListAssign__vtable;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
