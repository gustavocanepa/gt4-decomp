#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0038B7C0(s32, s32);                /* extern */
s32 func_0038B8D8(s32, s32);                /* extern */
s32 RaceSolitaire__cleanup();                            /* extern */

void RaceMachineTest__cleanup(s32 arg0) {
    RaceSolitaire__cleanup();
    func_0038B7C0(arg0, 0);
    func_0038B8D8(arg0, 0);
}
