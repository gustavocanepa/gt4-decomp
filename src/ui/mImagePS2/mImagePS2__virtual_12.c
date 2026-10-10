#include "types.h"
#include "gt4/mImagePS2.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00499728(void *);                      /* extern */
s32 func_0049CC48(s32);                         /* extern */

s32 mImagePS2__virtual_12(struct mImagePS2 *arg0) {
    void *temp_v0;

    temp_v0 = arg0->unk14_pvoid;
    if (temp_v0 != NULL) {
        func_00499728(temp_v0);
        func_0049CC48(M2C_FIELD(arg0->unk14_pvoid, s32 *, 0x18));
    }
}
