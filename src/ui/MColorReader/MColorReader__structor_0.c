#include "types.h"
#include "gt4/MColorReader.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char MColorReader__vtable[];
s32 MColorReader__structor_0(struct MColorReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MColorReader__vtable;
}
