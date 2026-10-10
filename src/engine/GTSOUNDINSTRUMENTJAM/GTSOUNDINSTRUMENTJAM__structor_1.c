#include "types.h"
#include "gt4/GTSOUNDINSTRUMENTJAM.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 GTSOUNDINSTRUMENT__structor_0();                            /* extern */

extern char GTSOUNDINSTRUMENTJAM__vtable[];
void GTSOUNDINSTRUMENTJAM__structor_1(struct GTSOUNDINSTRUMENTJAM *arg0) {
    GTSOUNDINSTRUMENT__structor_0();
    arg0->unk20 = 0;
    arg0->unk1C = (s32)GTSOUNDINSTRUMENTJAM__vtable;
}
