#include "types.h"
#include "gt4/MstringReader.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char MstringReader__vtable[];
s32 MstringReader__structor_13(struct MstringReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MstringReader__vtable;
}
