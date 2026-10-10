#include "types.h"
#include "gt4/Concourse.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004080F8();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char Concourse__vtable[];
void Concourse__structor_1(struct Concourse *arg0, s32 arg1) {
    arg0->unk10 = (s32)Concourse__vtable;
    func_004080F8();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
