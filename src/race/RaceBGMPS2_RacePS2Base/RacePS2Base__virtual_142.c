#include "types.h"
#include "gt4/RacePS2Base.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_003C0FB0(s32);                             /* extern */

f32 RacePS2Base__virtual_142(struct RacePS2Base *arg0) {
    return func_003C0FB0(arg0->unk6C) * arg0->unkCF48;
}
