#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AF818();                                /* extern */
s32 func_004AFFB8(void *);                      /* extern */

struct func_004AFF60_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_004AFF60(struct func_004AFF60_arg0 *arg0) {
    s32 var_s1;

    var_s1 = -1;
    if (arg0->unk4 != 0) {
        var_s1 = func_004AF818();
        func_004AFFB8(arg0);
    }
    return var_s1;
}
