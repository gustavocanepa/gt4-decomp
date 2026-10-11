#include "types.h"
#include "gt4/mGameInputAnalog.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

extern char mGameInputAnalog__vtable[];
void mGameInputAnalog__structor_0(void *arg0) {
    hObject__structor_0();
    ((struct mGameInputAnalog *)arg0)->unk4 = (s32)mGameInputAnalog__vtable;
    func_005A48D8(arg0 + 0x10, 0, 0x42);
}
