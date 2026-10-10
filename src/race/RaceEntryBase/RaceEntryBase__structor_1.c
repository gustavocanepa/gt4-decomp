#include "types.h"
#include "gt4/RaceEntryBase.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003B6C98();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceEntryBase__vtable[];
void RaceEntryBase__structor_1(struct RaceEntryBase *arg0, s32 arg1) {
    arg0->unk20 = (s32)RaceEntryBase__vtable;
    func_003B6C98();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
