#include "types.h"
#include "gt4/RaceReplayInformation.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 RaceReplayInformation__getEntryCars(struct RaceReplayInformation *arg0) {
    return M2C_FIELD(arg0->unk130, s32 *, 0x958);
}
