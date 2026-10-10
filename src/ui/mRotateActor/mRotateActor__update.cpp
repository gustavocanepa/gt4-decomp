#include "types.h"
#include "gt4/mRotateActor.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 mWidget__setRotate(s32, f32);                    /* extern */
s32 func_002CDB30();                            /* extern */
s32 func_002CDBE8();                            /* extern */

void mRotateActor__update(void *arg0) {
    if (((struct mRotateActor *)arg0)->unk34 != 0) {
        func_002CDB30();
    } else {
        func_002CDBE8();
    }
    mWidget__setRotate(((struct mRotateActor *)arg0)->unk14, ((struct mRotateActor *)arg0)->unk20);
}
