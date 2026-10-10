#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceEntryCar__update(s32);                     /* extern */
s32 func_004A5400();                            /* extern */

void func_00452480(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    RaceEntryCar__update(1);
    func_004A5400();
    RaceEntryCar__update(0);
    func_004A5400();
}
