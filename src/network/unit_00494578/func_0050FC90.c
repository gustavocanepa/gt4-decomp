/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0050F808();                                /* extern */
s32 func_0057D9C0(s32);                     /* extern */

extern char D_006C2290[];
s32 func_0050FC90(s32 arg0) {
    s32 var_v0;

    var_v0 = -0xC;
    if (arg0 != 0) {
        var_v0 = func_0050F808();
        if (var_v0 != 0) {
            func_0057D9C0((s32)D_006C2290);
            var_v0 = -0xD;
        }
    }
    return var_v0;
}
