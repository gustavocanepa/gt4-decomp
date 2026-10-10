#include "types.h"
#include "gt4/PropNameSearcher.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0041B4D0(s32);                             /* extern */

void PropNameSearcher__virtual_00(struct PropNameSearcher *arg0, s32 arg1) {
    if ((arg1 != 0) && (arg0->unk4 == 0) && (func_0041B4D0(arg1) < 0)) {
        arg0->unk4 = arg1;
    }
}
