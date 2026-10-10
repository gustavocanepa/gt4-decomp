#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 AutomaticFader__update(s32);                         /* extern */
s32 RaceMTRMultiFunctionDisplay__update_auto_info(s32, f32);                    /* extern */

void RaceMTRMultiFunctionDisplay__update(s32 arg0, f32 fparg0) {
    AutomaticFader__update(arg0 + 0x20);
    RaceMTRMultiFunctionDisplay__update_auto_info(arg0, fparg0);
}
