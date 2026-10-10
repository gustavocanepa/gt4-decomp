#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00206868();                             /* extern */
s32 func_00206888(s32, s32, s32);               /* extern */
s32 func_00206B80(s32, s32);                    /* extern */
s32 func_0025C300(s32);                             /* extern */
s32 func_002D7F98(s32 *, s32, s32, s32);            /* extern */
s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void func_002D8020(s32 arg0, s32 *arg1) {
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    if (*arg1 != 0) {
        temp_v0 = func_00206868();
        if (temp_v0 != 0) {
            var_s0 = func_0025C300(temp_v0);
            if (var_s0 != 0) {
                do {
                    temp_s3 = func_0025C300(var_s0);
                    temp_v0_2 = func_002D7F98(arg1, var_s0, func_00206868(arg0), var_s0);
                    if (temp_v0_2 != var_s0) {
                        func_003285A8(var_s0);
                        func_00206B80(arg0, var_s0);
                        func_00206888(arg0, var_s0, temp_v0_2);
                        func_003285F8(var_s0);
                    }
                    var_s0 = temp_s3;
                } while (var_s0 != 0);
            }
        }
    }
}
