#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0021A828(s32, s32);                    /* extern */
s32 func_0021A858(s32, s32);                    /* extern */

void func_002BCB00(s32 arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0xA0;
    func_0021A828(temp_s1, arg0 + 0x2E4);
    func_0021A858(temp_s1, arg0 + 0x2F0);
}
