#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 RaceCarSound__setNarration(s32);                         /* extern */
s32 BGM__narrationPause(s32);                         /* extern */

struct func_003BA8B8_arg0 {
    char pad0[0x24698];
    s32 unk24698;
    char pad2469C[0x4];
    s32 unk246A0;
    s32 unk246A4;
};

void RaceFreeRun__setDescriptionVoicePause(struct func_003BA8B8_arg0 *arg0, s32 arg1) {
    if ((arg0->unk246A0 != 0) && (arg0->unk24698 != 0) && (arg0->unk246A4 != arg1)) {
        RaceCarSound__setNarration(arg1 ^ 1);
        BGM__narrationPause(arg1);
        arg0->unk246A4 = arg1;
    }
}
