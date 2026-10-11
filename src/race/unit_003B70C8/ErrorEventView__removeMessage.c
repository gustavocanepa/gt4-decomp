#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceEventQueue__get(s32, s32, void *, s32);   /* extern */

void ErrorEventView__removeMessage(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    do {

    } while (RaceEventQueue__get(arg1 + 0xF4, 0x1B, sp, 1) != 0);
}
