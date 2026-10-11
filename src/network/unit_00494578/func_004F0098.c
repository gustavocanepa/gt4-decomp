#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00503150();                            /* extern */
s32 func_00572578(s32);                         /* extern */
s32 free(s32);                         /* extern */

extern char D_006454F0[];
s32 func_004F0098(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v0;

    func_00503150();
    temp_v0 = func_00572578((s32)D_006454F0);
    if (temp_v0 != 0) {
        free(temp_v0);
    }
}
