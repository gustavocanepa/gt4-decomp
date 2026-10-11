#include "types.h"
#include "gt4/MRegionReader.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char MRegionReader__vtable[];
s32 MRegionReader__structor_0(struct MRegionReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MRegionReader__vtable;
}
