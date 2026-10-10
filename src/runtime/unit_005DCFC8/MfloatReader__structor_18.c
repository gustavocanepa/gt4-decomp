#include "types.h"
#include "gt4/MfloatReader.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char MfloatReader__vtable[];
s32 MfloatReader__structor_18(struct MfloatReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MfloatReader__vtable;
}
