#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00548008(s32);                         /* extern */
s32 func_0055C860(s32, s32);                /* extern */

extern char SDDRV__VoiceSystem__master_[];
void func_00462878(s32 arg0) {
    func_0055C860((s32)SDDRV__VoiceSystem__master_, arg0);
    func_00548008(arg0 == 0);
}
