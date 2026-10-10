#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_004F8A68(s32);                           /* extern */

struct func_004F9E60_temp_v0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_004F9E60(s32 arg0) {
    s32 var_v1;
    struct func_004F9E60_temp_v0 *temp_v0;

    temp_v0 = func_004F8A68(arg0 + 0xCD8);
    var_v1 = -1;
    if (temp_v0 != NULL) {
        var_v1 = temp_v0->unk4;
    }
    return var_v1;
}
