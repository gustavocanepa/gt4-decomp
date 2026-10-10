#include "types.h"
#include "gt4/RaceInputLan.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 AutomobileControlRecord__Recorder__read(void *);                      /* extern */

s32 RaceInput__replayControl(void *arg0) {
    if (((struct RaceInputLan *)arg0)->unk1D0 == 0) {
        AutomobileControlRecord__Recorder__read(arg0 + 0xDC);
    }
}
