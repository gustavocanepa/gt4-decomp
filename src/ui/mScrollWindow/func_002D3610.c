#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00235C00(s32);                             /* extern */
s32 func_0025C1E8(void *);                          /* extern */
s32 func_00266088(s32);                             /* extern */
s32 func_002D3430(void *, s32, s32, s32);       /* extern */

struct func_002D3610_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

s32 func_002D3610(struct func_002D3610_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (func_00266088(arg0->unkBC) != 0) {
        temp_v0 = func_0025C1E8(arg0);
        if (temp_v0 != 0) {
            temp_v0_2 = func_00235C00(temp_v0);
            if (temp_v0_2 != 0) {
                func_002D3430(arg0, temp_v0_2, arg1, arg2);
                return 1;
            }
        }
    }
    return 0;
}
