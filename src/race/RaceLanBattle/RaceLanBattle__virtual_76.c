#include "types.h"
#include "gt4/RaceLanBattle.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00336008(void *);                          /* extern */
s32 RaceBasic__updatePause(void *);                      /* extern */

void RaceLanBattle__virtual_76(void *arg0) {
loop_1:
    if (((struct RaceLanBattle *)arg0)->unkF378 == 0) {
        if (((struct RaceLanBattle *)arg0)->unkF38C == 0) {
            RaceBasic__updatePause(arg0);
        }
        if ((((struct RaceLanBattle *)arg0)->unkE468 == 0) && (func_00336008(arg0 + 0xE488) != 0)) {
            goto loop_1;
        }
    }
}
