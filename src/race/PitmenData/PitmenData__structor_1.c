#include "types.h"
#include "gt4/PitmenData.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003D59F8();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char PitmenData__vtable[];
void PitmenData__structor_1(struct PitmenData *arg0, s32 arg1) {
    arg0->unk6C = (s32)PitmenData__vtable;
    func_003D59F8();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
