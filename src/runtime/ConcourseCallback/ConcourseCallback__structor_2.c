#include "types.h"
#include "gt4/ConcourseCallback.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char ConcourseCallback__vtable[];
s32 ConcourseCallback__structor_2(struct ConcourseCallback *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)ConcourseCallback__vtable;
}
