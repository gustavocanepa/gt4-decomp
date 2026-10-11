#include "types.h"
#include "gt4/ResultLicense.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceResultBase__structor_0(void *, s32);             /* extern */
s32 func_003E1BC0();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char ResultLicense__vtable[];
void ResultLicense__structor_1(struct ResultLicense *arg0, s32 arg1) {
    arg0->unkC = (s32)ResultLicense__vtable;
    func_003E1BC0();
    RaceResultBase__structor_0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
