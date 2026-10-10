#define GT4_DECLS
#include "gt4/mWidget.h"
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00266088();                                /* extern */
s32 func_002DB300(s32, s32);                    /* extern */

s32 func_002DB148(s32 arg0) {
    if (func_00266088() != 0) {
        func_002DB300(arg0, mWidget__getRootWindow(arg0));
    }
}
