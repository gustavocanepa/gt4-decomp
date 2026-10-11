#include "types.h"
#include "gt4/CarIconMaker.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

void GranTurismo4__GameObjectBase__stop(void *arg0) {
    func_00576788();
    if (((struct CarIconMaker *)arg0)->unk5C != 0) {
        ((struct CarIconMaker *)arg0)->unk60 = 1;
    }
    func_005767C0(arg0);
}
