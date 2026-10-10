#include "types.h"
#include "gt4/Concourse.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003E73F0();                            /* extern */

extern char Concourse__vtable[];
void Concourse__structor_0(struct Concourse *arg0) {
    func_003E73F0();
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk10 = (s32)Concourse__vtable;
}
