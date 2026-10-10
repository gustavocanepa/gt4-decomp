#include "types.h"
#include "gt4/DriverCallback.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char DriverCallback__vtable[];
s32 DriverCallback__structor_2(struct DriverCallback *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)DriverCallback__vtable;
}
