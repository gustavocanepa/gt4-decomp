#include "types.h"
#include "gt4/CarIconMaker.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectBase__internal_render();                            /* extern */

s32 GranTurismo4__GameObjectPS2__internal_render(struct CarIconMaker *arg0) {
    if (arg0->unk68 < 2) {
        GranTurismo4__GameObjectBase__internal_render();
    }
}
