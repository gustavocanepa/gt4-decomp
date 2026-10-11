#include "types.h"
#include "gt4/DynamicsConductor.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 EnemyLineProcessorOld__structor_1(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char DynamicsConductor__vtable[];
void DynamicsConductor__structor_1(void *arg0, s32 arg1) {
    ((struct DynamicsConductor *)arg0)->unk10140 = (s32)DynamicsConductor__vtable;
    EnemyLineProcessorOld__structor_1(arg0 + 0xDA50, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
