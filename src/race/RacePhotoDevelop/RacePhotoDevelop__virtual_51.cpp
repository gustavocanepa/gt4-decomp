#include "gt4/RacePhotoDevelop.h"
typedef int s32;

extern "C" s32 RaceBase__getDefaultCarModelType(void *arg0);

extern "C" s32 RacePhotoDevelop__virtual_51(struct RacePhotoDevelop *arg0) {
    if (arg0->unk2EF30 != 0) {
        return 4;
    }
    return RaceBase__getDefaultCarModelType(arg0);
}
