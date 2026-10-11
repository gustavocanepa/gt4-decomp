#include "types.h"
#include "gt4/CarIconMaker.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectBase__stop();                            /* extern */
s32 func_00576788(void *);                      /* extern */
s32 func_005767C0(void *);                      /* extern */
s32 func_005767E0(void *);                      /* extern */

void GranTurismo4__GameObjectBase__sync(void *arg0) {
    GranTurismo4__GameObjectBase__stop();
    func_00576788(arg0);
    if (((struct CarIconMaker *)arg0)->unk5C != 0) {
        func_005767E0(arg0);
    }
    func_005767C0(arg0);
}
