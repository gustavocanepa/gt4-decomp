#include "types.h"
#include "gt4/hFloat.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 hFloat__toFloat(void *arg0) {
    return ((struct hFloat *)arg0)->unk10;
}
