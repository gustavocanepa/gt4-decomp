#include "types.h"
#include "gt4/mModelStream.h"
void *memcpy(void *, const void *, unsigned int);

s32 mModelStream__isValid(struct mModelStream *arg0) {
    return arg0->unk28 != 0;
}
