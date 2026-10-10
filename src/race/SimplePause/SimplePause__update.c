#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 PauseBase__checkTimeLimit(s32);                             /* extern */
s32 PauseBase__clearTimeCount(s32);                         /* extern */
s32 RaceInput__getButtonDown(s32);                             /* extern */

s32 SimplePause__update(s32 arg0, s32 arg1) {
    if ((RaceInput__getButtonDown(arg1) & 0x80) || (RaceInput__getButtonDown(arg1) & 0x20)) {
        PauseBase__clearTimeCount(arg0);
        return 3;
    }
    return (PauseBase__checkTimeLimit(arg0) == 0) ? 0 : 2;
}
