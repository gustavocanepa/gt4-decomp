#define GT4_DECLS
#include "gt4/mWidget.h"
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00200EC8(s32);                             /* extern */
f32 func_00200ED8(s32);                             /* extern */
s32 func_00206868(s32);                             /* extern */
s32 func_0025BF90(s32);                         /* extern */
s32 func_0025C300(s32);                             /* extern */
s32 func_00265D98(s32);                             /* extern */
s32 func_002662A0(void *);                          /* extern */
s32 func_00266378(s32, s32);                /* extern */
s32 func_002663D8(s32, s32);                /* extern */
f32 func_002E94E0(s32);                             /* extern */

struct func_002C8FA8_arg0 {
    char pad0[0xC4];
    s32 unkC4;
};

f32 func_002C8FA8(struct func_002C8FA8_arg0 *arg0) {
    f32 var_f20;
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    var_f20 = func_00200EC8(arg0->unkC4);
    var_s0 = func_00206868(arg0->unkC4);
    if (var_s0 != 0) {
        do {
            if (func_00265D98(var_s0) == 0) {
                if (var_s2 > 0) {
                    var_f20 += func_002E94E0(arg0->unkC4);
                }
                if (func_002662A0(arg0) == 0) {
                    func_00266378(var_s0, 1);
                    func_002663D8(var_s0, 1);
                    func_0025BF90(var_s0);
                }
                mWidget__setWindowY(var_s0, var_f20);
                var_s2 += 1;
                var_f20 += mWidget__getWindowH(var_s0);
            }
            var_s0 = func_0025C300(var_s0);
        } while (var_s0 != 0);
    }
    return var_f20 + func_00200ED8(arg0->unkC4);
}
