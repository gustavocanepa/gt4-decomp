#include "types.h"
#include "gt4/RaceInput.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003467A0(void *, s32);             /* extern */
s32 func_0043A108(void *, s32);             /* extern */
s32 func_0055F738(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceInput__vtable[];
void RaceInput__structor_2(void *arg0, s32 arg1) {
    ((struct RaceInput *)arg0)->unkD0_s32 = (s32)RaceInput__vtable;
    func_0043A108(arg0 + 0x1A0, 2);
    func_0043A108(arg0 + 0x170, 2);
    func_003467A0(arg0 + 0xD4, 2);
    func_0055F738(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
