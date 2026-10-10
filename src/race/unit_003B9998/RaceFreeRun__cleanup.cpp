#include "types.h"
#include "gt4/RaceFreeRun.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0038B7C0(void *, s32);             /* extern */
s32 func_0038B8D8(void *, s32);             /* extern */
s32 func_0038B990(void *, s32);             /* extern */
s32 func_0038BA90(void *, s32);             /* extern */
s32 func_0038BAB0(void *, s32);             /* extern */
s32 RaceFreeRun__setDescriptionVoicePlay(void *, s32);             /* extern */
s32 RaceSolitaire__cleanup();                            /* extern */
s32 BGM__narrationFreeBuffer();                            /* extern */

void RaceFreeRun__cleanup(void *arg0) {
    RaceSolitaire__cleanup();
    ((struct RaceFreeRun *)arg0)->unk24698 = 0;
    ((struct RaceFreeRun *)arg0)->unk246A4 = 0;
    ((struct RaceFreeRun *)arg0)->unk246A0 = 0;
    RaceFreeRun__setDescriptionVoicePlay(arg0, 0);
    BGM__narrationFreeBuffer();
    func_0038B7C0(arg0, 0);
    func_0038B8D8(arg0, 0);
    func_0038BAB0(arg0, 0);
    func_0038B990(arg0, 0);
    func_0038BA90(arg0, 0);
}
