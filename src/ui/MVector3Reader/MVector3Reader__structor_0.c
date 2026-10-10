#include "types.h"
#include "gt4/MVector3Reader.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char MVector3Reader__vtable[];
s32 MVector3Reader__structor_0(struct MVector3Reader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MVector3Reader__vtable;
}
