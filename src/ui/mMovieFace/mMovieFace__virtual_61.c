#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 MboolReader__structor_4(s32, s32);                        /* extern */
s32 MboolReader__structor_11();                                /* extern */

s32 mMovieFace__virtual_61(s32 arg0, s32 arg1) {
    if (MboolReader__structor_11() != 0) {
        return 1;
    }
    return MboolReader__structor_4(arg0 + 0xF0, arg1) != 0;
}
