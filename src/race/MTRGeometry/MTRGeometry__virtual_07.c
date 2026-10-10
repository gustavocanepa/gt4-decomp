#include "types.h"
#include "gt4/MTRGeometry.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 MTRGeometry__virtual_07(struct MTRGeometry *p, s32 s) {
    f32 r;
    if (p->unk4 == 0) {
        r = -0x1.22D0E4p-4f;
        if (s) r = 0x1.22D0E4p-4f;
    } else {
        r = -0x1.395810p-3f;
        if (s) r = 0x1.395810p-3f;
    }
    return r;

}
