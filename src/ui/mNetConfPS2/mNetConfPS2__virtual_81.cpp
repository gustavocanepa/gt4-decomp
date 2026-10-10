#include "types.h"
#include "gt4/mNetConfPS2.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004ED050(s32);                         /* extern */
s32 func_004ED1F8(s32);                         /* extern */
s32 exception__structor_0(s32);                         /* extern */

void mNetConfPS2__virtual_81(void *arg0) {
    s32 var_s0;

    var_s0 = ((struct mNetConfPS2 *)arg0)->unk268_s32;
    if (var_s0 == 0) {
        var_s0 = exception__structor_0(0x64);
        func_004ED050(var_s0);
        ((struct mNetConfPS2 *)arg0)->unk268_s32 = var_s0;
    }
    func_004ED1F8(var_s0);
}
