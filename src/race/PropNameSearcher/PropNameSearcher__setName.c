#include "types.h"
#include "gt4/PropNameSearcher.h"
void *memcpy(void *, const void *, unsigned int);

s32 pdiRiderman__Skeleton__getBoneIndex(s32);                             /* extern */

void PropNameSearcher__setName(struct PropNameSearcher *arg0, s32 arg1) {
    if ((arg1 != 0) && (arg0->unk4 == 0) && (pdiRiderman__Skeleton__getBoneIndex(arg1) < 0)) {
        arg0->unk4 = arg1;
    }
}
