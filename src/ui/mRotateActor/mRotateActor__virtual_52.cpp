#include "types.h"
#include "gt4/mRotateActor.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00267D18(s32, f32);                    /* extern */
s32 func_002CDB30();                            /* extern */
s32 func_002CDBE8();                            /* extern */

void mRotateActor__virtual_52(void *arg0) {
    if (((struct mRotateActor *)arg0)->unk34 != 0) {
        func_002CDB30();
    } else {
        func_002CDBE8();
    }
    func_00267D18(((struct mRotateActor *)arg0)->unk14, ((struct mRotateActor *)arg0)->unk20);
}
