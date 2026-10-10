#include "types.h"
#include "gt4/CarIconMaker.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 CarIconMaker__virtual_02();                            /* extern */
s32 func_00576788(void *);                      /* extern */
s32 func_005767C0(void *);                      /* extern */
s32 func_005767E0(void *);                      /* extern */

void CarIconMaker__virtual_03(void *arg0) {
    CarIconMaker__virtual_02();
    func_00576788(arg0);
    if (((struct CarIconMaker *)arg0)->unk5C != 0) {
        func_005767E0(arg0);
    }
    func_005767C0(arg0);
}
