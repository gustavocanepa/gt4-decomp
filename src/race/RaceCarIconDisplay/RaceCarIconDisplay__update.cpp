#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 Oscillator__update(s32, f32);                    /* extern */
s32 AutomaticFader__update(s32);                         /* extern */

void RaceCarIconDisplay__update(s32 arg0, f32 fparg0) {
    AutomaticFader__update(arg0 + 0x28);
    Oscillator__update(arg0 + 0x44, fparg0);
}
