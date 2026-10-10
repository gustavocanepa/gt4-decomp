#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00548008(s32);                         /* extern */
s32 func_0055C860(s32, s32);                /* extern */

extern char D_006518C8[];
void func_00462878(s32 arg0) {
    func_0055C860((s32)D_006518C8, arg0);
    func_00548008(arg0 == 0);
}
