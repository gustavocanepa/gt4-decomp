#include "types.h"
#include "gt4/GTSOUNDINSTRUMENTJAM.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char GTSOUNDINSTRUMENTJAM__vtable[];
struct GTSOUNDINSTRUMENT {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    void * unk1C;
};
s32 func_005C1628(struct GTSOUNDINSTRUMENTJAM *); /* extern */

void GTSOUNDINSTRUMENTJAM__structor_2(struct GTSOUNDINSTRUMENTJAM *arg0, s32 arg1) {
    arg0->unk1C_pvoid = (void *)(s32)GTSOUNDINSTRUMENTJAM__vtable;
    GTSOUNDINSTRUMENT__structor_1((struct GTSOUNDINSTRUMENT *) arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
