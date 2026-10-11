#include "types.h"
#include "gt4/PitmanCallback.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char PitmanCallback__vtable[];
s32 PitmanCallback__structor_2(struct PitmanCallback *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)PitmanCallback__vtable;
}
