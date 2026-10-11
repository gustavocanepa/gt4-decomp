#include "types.h"
#include "gt4/DynamicsConductorSinglePlayer.h"
void *memcpy(void *, const void *, unsigned int);

s32 DynamicsConductorBattle2P__virtual_26();                            /* extern */
s32 func_00353570(void *);                      /* extern */

void DynamicsConductorSinglePlayer__virtual_26(struct DynamicsConductorSinglePlayer *arg0) {
    DynamicsConductorBattle2P__virtual_26();
    if ((arg0->unkF886 != 0) && (arg0->unkF884 < 0) && (arg0->unkF887 != 0)) {
        arg0->unkCBE4 = 1;
    }
    func_00353570(arg0);
}
