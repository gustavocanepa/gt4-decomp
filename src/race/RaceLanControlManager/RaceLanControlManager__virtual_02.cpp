#include "types.h"
#include "gt4/RaceLanControlManager.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00337980(s32);                         /* extern */
s32 func_0055FBA8(void *);                      /* extern */

void RaceLanControlManager__virtual_02(void *arg0) {
    func_00337980(((struct RaceLanControlManager *)arg0)->unk64);
    func_0055FBA8(arg0);
}
