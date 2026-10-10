#include "types.h"
#include "gt4/MboolReader.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char MboolReader__vtable[];
s32 MboolReader__structor_20(struct MboolReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MboolReader__vtable;
}
