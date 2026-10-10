#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 SPEC_DATABASE__DatabaseTable__searchNumber();                                /* extern */
s32 SPEC_DATABASE__DatabaseTable__getRowN(s32, s32, s32);               /* extern */

void SPEC_DATABASE__DatabaseTable__getRow(s32 arg0, s32 arg1, s32 arg2) {
    SPEC_DATABASE__DatabaseTable__getRowN(arg0, SPEC_DATABASE__DatabaseTable__searchNumber(), arg2);
}
