#include "types.h"
#include "gt4/RacePhotoDevelop.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectPS2__terminate(void *);                      /* extern */
s32 func_003C8A38();                            /* extern */

void RacePhotoDevelop__virtual_06(void *arg0) {
    if ((((struct RacePhotoDevelop *)arg0)->unk2EF3C < 0) && (((struct RacePhotoDevelop *)arg0)->unk2EF40 == 0)) {
        func_003C8A38();
        GranTurismo4__GameObjectPS2__terminate(arg0);
    }
}
