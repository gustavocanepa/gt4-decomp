#include "types.h"
#include "gt4/RaceInputLan.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00345D70(void *);                      /* extern */

s32 RaceInputLan__virtual_06(void *arg0) {
    if (((struct RaceInputLan *)arg0)->unk1D0 == 0) {
        func_00345D70(arg0 + 0xDC);
    }
}
