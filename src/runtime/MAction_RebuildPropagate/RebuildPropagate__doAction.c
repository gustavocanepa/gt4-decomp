/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#include "gt4/RebuildPropagate.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00234798(s32, s32);                    /* extern */
s32 mWidget__GetClassID();                                /* extern */
s32 mWidget__canDefault(s32);                             /* extern */
s32 hObject__isInstanceOf(s32, s32);                        /* extern */

void RebuildPropagate__doAction(struct RebuildPropagate *arg0, s32 arg1) {
    if ((hObject__isInstanceOf(arg1, mWidget__GetClassID()) != 0) && (mWidget__canDefault(arg1) != 0)) {
        func_00234798(arg0->unk4, arg1);
    }
}
