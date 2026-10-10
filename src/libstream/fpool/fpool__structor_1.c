#include "types.h"
#include "gt4/fpool.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char fpool__vtable[];
void fpool__structor_1(struct fpool *arg0, s32 arg1) {
    arg0->unk1C = (s32)fpool__vtable;
    func_00575DA0(arg0->unk10);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
