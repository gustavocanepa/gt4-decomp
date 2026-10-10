#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 DynamicsConductor__getSpecialStart_Handicap(s32, s32, s32, s32, s32);     /* extern */
s32 DynamicsConductor__getSpecialStart_Launch(s32, s32, s32, s32, s32);     /* extern */
s32 DynamicsConductor__getSpecialStart_Rolling_ByBalance();                                /* extern */

void DynamicsConductorLicense__getSpecialStart(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (DynamicsConductor__getSpecialStart_Rolling_ByBalance() == 0) {
        DynamicsConductor__getSpecialStart_Handicap(arg0, arg1, arg2, arg3, arg4);
        DynamicsConductor__getSpecialStart_Launch(arg0, arg1, arg2, arg3, arg4);
    }
}
