#include "types.h"
#include "gt4/MTRGeometry.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char MTRGeometry__vtable[];
s32 MTRGeometry__structor_2(struct MTRGeometry *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)MTRGeometry__vtable;
}
