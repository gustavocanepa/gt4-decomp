#include "gt4/RaceLanBattle.h"
typedef int s32;

extern "C" s32 RacePS2Base__render_use_back_mirror(struct RaceLanBattle *arg0);

extern "C" s32 RaceLanBattle__virtual_117(struct RaceLanBattle *arg0) {
    s32 v1 = 0;

    if (arg0->unkE458 != 0) {
        v1 = RacePS2Base__render_use_back_mirror(arg0) != 0;
    }
    return v1;
}
