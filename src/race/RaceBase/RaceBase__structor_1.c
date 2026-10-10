#include "types.h"
#include "gt4/RaceBase.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00101078(void *, s32);             /* extern */
s32 SceneCameraBase__structor_0(void *, s32);             /* extern */
s32 func_00574DA8(s32, s32);                /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceBase__vtable[];
void RaceBase__structor_1(void *arg0, s32 arg1) {
    ((struct RaceBase *)arg0)->unk64 = (s32)RaceBase__vtable;
    func_00574DA8(arg0 + 0xCE4, 2);
    SceneCameraBase__structor_0(arg0 + 0x80, 2);
    func_00101078(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
