#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00435668_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

void *func_00435668(void *arg0) {
    s32 temp_v1;

    temp_v1 = ((struct func_00435668_arg0 *)arg0)->unk81C8;
    return arg0 + (((temp_v1 < 0) ? 0 : temp_v1) << 5) + 8;
}
