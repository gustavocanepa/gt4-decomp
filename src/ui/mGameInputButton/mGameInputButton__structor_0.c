#include "types.h"
#include "gt4/mGameInputButton.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

extern char mGameInputButton__vtable[];
void mGameInputButton__structor_0(void *arg0) {
    hObject__structor_0();
    ((struct mGameInputButton *)arg0)->unk4 = (s32)mGameInputButton__vtable;
    func_005A48D8(arg0 + 0x10, 0, 0x24);
}
