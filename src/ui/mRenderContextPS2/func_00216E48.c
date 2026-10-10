#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004A1638(s32);                     /* extern */

struct func_00216E48_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_00216E48(struct func_00216E48_arg0 *arg0) {
    if (arg0->unk4 == 2) {
        func_004A1638(7);
    }
}
