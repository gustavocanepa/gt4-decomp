#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceBasic__cleanup();                            /* extern */
s32 func_0038B7C0(s32, s32);                /* extern */
s32 func_0038B8D8(s32, s32);                /* extern */
s32 func_0038B990(s32, s32);                /* extern */
s32 func_0038BA90(s32, s32);                /* extern */
s32 func_0038BAB0(s32, s32);                /* extern */

void RaceChampionship__cleanup(s32 arg0) {
    RaceBasic__cleanup();
    func_0038B7C0(arg0, 0);
    func_0038BAB0(arg0, 0);
    func_0038B990(arg0, 0);
    func_0038BA90(arg0, 0);
    func_0038B8D8(arg0, 0);
}
