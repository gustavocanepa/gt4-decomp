#include "types.h"
#include "gt4/RacePS2Base.h"
void *memcpy(void *, const void *, unsigned int);

s32 RacePS2Base__soundMute(struct RacePS2Base *arg0) {
    return arg0->unkCFBC;
}
