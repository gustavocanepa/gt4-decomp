#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00206868();                             /* extern */
s32 func_00206888(s32, s32, s32);               /* extern */
s32 func_00206B80(s32, s32);                    /* extern */
s32 func_00255088(void *, s32 *);               /* extern */
s32 func_002550B8(void *, s32);             /* extern */
s32 func_0025C300(s32);                             /* extern */
s32 func_002DBE50(s32 *, s32, s32, s32);            /* extern */

void func_002DBF20(s32 arg0, s32 *arg1) {
    s8 sp[0x10];
    s32 sp10;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_s0;

    if (*arg1 != 0) {
        var_s0 = func_0025C300(func_00206868());
        if (var_s0 != 0) {
            do {
                temp_s3 = func_0025C300(var_s0);
                temp_v0 = func_002DBE50(arg1, var_s0, func_00206868(arg0), var_s0);
                if (temp_v0 != var_s0) {
                    sp10 = var_s0;
                    func_00255088(sp, &sp10);
                    func_00206B80(arg0, var_s0);
                    func_00206888(arg0, var_s0, temp_v0);
                    func_002550B8(sp, 2);
                }
                var_s0 = temp_s3;
            } while (var_s0 != 0);
        }
    }
}
