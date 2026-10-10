#include "types.h"
#include "gt4/CarIconMaker.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

void GranTurismo4__GameObjectPS2__terminate(void *arg0) {
    func_00576788();
    if (((struct CarIconMaker *)arg0)->unk68 == 0) {
        ((struct CarIconMaker *)arg0)->unk68 = 1;
    }
    func_005767C0(arg0);
}
