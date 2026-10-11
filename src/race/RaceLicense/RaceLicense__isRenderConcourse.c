#include "types.h"
#include "gt4/RaceLicense.h"
void *memcpy(void *, const void *, unsigned int);

s32 RaceLicense__isRenderConcourse(struct RaceLicense *arg0) {
    return (u32) arg0->unkCC8 < 2U;
}
