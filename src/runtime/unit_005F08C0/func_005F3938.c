#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F3938_arg0 {
    char pad0[0xE10];
    s32 unkE10;
};

void *func_005F3938(void *arg0) {
    return arg0 + ((1 - ((struct func_005F3938_arg0 *)arg0)->unkE10) * 0x700) + 0x10;
}
