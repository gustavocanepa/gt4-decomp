#include "types.h"
#include "gt4/mGameStats.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 memcpy(void *, void *, s32);         /* extern */

extern char mGameStats__vtable[];
void mGameStats__structor_0(void *arg0, void *arg1) {
    void *temp_a1;

    hObject__structor_0(arg0);
    ((struct mGameStats *)arg0)->unk4 = (s32)mGameStats__vtable;
    temp_a1 = *(s32 *)arg1;
    memcpy(arg0 + 0x10, temp_a1, M2C_FIELD(temp_a1, s32 *, -0x10));
}
