#include "types.h"
#include "gt4/RaceReplayInformation.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s64 RaceReplayInformation__getRaceCode(struct RaceReplayInformation *arg0) {
    return M2C_FIELD(arg0->unk130, s64 *, 0xB0);
}
