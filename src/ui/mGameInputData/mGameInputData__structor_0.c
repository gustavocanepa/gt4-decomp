#include "types.h"
#include "gt4/mGameInputData.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */
s32 func_0055F250(s32, s32, s32, s32, s32); /* extern */

extern char mGameInputData__vtable[];
void mGameInputData__structor_0(void *arg0) {
    hObject__structor_0();
    ((struct mGameInputData *)arg0)->unk4 = (s32)mGameInputData__vtable;
    func_0055F250(arg0 + 0x14, 0, 0, 0, 0);
}
