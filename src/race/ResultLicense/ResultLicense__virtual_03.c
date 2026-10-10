#include "types.h"
#include "gt4/ResultLicense.h"
void *memcpy(void *, const void *, unsigned int);

s32 ResultArcade__virtual_03();                            /* extern */
s32 func_003E1C80(void *, s32);                 /* extern */
s32 func_003E1E10(void *, s32);                 /* extern */

void ResultLicense__virtual_03(struct ResultLicense *arg0, s32 arg1) {
    ResultArcade__virtual_03();
    func_003E1C80(arg0, arg1);
    func_003E1E10(arg0, arg1);
    arg0->unk580 = 0.016666666f;
}
