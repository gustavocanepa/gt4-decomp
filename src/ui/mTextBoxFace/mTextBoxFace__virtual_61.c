#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 MboolReader__structor_7(s32, s32);                        /* extern */
s32 MfloatReader__structor_11();                                /* extern */

s32 mTextBoxFace__virtual_61(s32 arg0, s32 arg1) {
    if (MfloatReader__structor_11() != 0) {
        return 1;
    }
    return MboolReader__structor_7(arg0 + 0xC0, arg1) != 0;
}
