#include "types.h"
#include "gt4/RaceCarModel.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003B1840(void *);                      /* extern */

s32 RaceCarModel__virtual_28(void *arg0) {
    if (((struct RaceCarModel *)arg0)->unk1670 != 0) {
        func_003B1840(arg0 + 0x5E0);
    }
    if (((struct RaceCarModel *)arg0)->unk1674 != 0) {
        func_003B1840(arg0 + 0xE20);
    }
}
