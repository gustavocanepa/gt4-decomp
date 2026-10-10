#include "types.h"
#include "gt4/MRectangleReader.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char MRectangleReader__vtable[];
s32 MRectangleReader__structor_0(struct MRectangleReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MRectangleReader__vtable;
}
