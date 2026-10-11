#include "types.h"
#include "gt4/mNetConfPS2.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00275830(void *);                      /* extern */
s32 func_004ED3A8(s32);                         /* extern */

void mNetConfPS2__virtual_98(void *arg0) {
    func_004ED3A8(((struct mNetConfPS2 *)arg0)->unk268_s32);
    func_00275830(arg0);
}
