#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 free(s32);                         /* extern */

extern char D_00620238[];
extern char D_0062023C[];
extern char D_00620240[];
void func_00346678(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    free(*(s32 *)(s32)D_00620238);
    *(s32 *)(s32)D_00620238 = 0;
    *(s32 *)D_0062023C = 0;
    *(s32 *)D_00620240 = 0;
}
