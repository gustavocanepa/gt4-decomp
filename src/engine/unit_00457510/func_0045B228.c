#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0045B0F8(void *);                          /* extern */

struct func_0045B228_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_0045B228(struct func_0045B228_arg0 *arg0) {
    s32 temp_s1;

    temp_s1 = arg0->unk8;
    do {

    } while (func_0045B0F8(arg0) != 0);
    return temp_s1;
}
