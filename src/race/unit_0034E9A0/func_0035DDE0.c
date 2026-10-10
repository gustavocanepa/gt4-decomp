#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 Automobile__getTripMeter(void);
extern s32 PDISTD__UNIT_MANAGER;
f32 func_0035DDE0(void) {
    f32 f = Automobile__getTripMeter();
    if (PDISTD__UNIT_MANAGER == 1) {
        f *= 0.625f;
    }
    return f;
}
