#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 Oscillator__update(s32);                         /* extern */
s32 AutomaticFader__update(s32, f32);                    /* extern */

void RaceMessageDisplay__update(s32 arg0, f32 fparg0) {
    Oscillator__update(arg0 + 0x34);
    AutomaticFader__update(arg0 + 0x54, fparg0);
}
