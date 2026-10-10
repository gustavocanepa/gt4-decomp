#include "types.h"
#include "gt4/HumanModel.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 HumanModel__virtual_03();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char HumanModel__vtable[];
void HumanModel__structor_1(struct HumanModel *arg0, s32 arg1) {
    arg0->unk7DC = (s32)HumanModel__vtable;
    HumanModel__virtual_03();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
