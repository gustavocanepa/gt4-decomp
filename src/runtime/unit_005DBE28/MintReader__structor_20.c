#include "types.h"
#include "gt4/MintReader.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char MintReader__vtable[];
s32 MintReader__structor_20(struct MintReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MintReader__vtable;
}
