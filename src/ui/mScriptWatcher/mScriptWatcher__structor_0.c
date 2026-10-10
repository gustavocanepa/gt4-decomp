#include "types.h"
#include "gt4/mScriptWatcher.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 mWatcher__structor_0();                            /* extern */
s32 func_002FA120(s32);                         /* extern */

extern char mScriptWatcher__vtable[];
void mScriptWatcher__structor_0(void *arg0) {
    mWatcher__structor_0();
    ((struct mScriptWatcher *)arg0)->unk4 = (s32)mScriptWatcher__vtable;
    func_002FA120(arg0 + 0x20);
    ((struct mScriptWatcher *)arg0)->unk24 = 0;
}
