#include "types.h"
#include "gt4/RefCounter.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char RefCounter__vtable[];
s32 RefCounter__structor_0(struct RefCounter *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = (s32)RefCounter__vtable;
}
