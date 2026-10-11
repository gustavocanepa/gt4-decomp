#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0043AC68_temp_v0_2 {
    char pad0[0xA58];
    s32 unkA58;
};
struct func_0043AC68_temp_a0 {
    char pad0[0xB6C4];
    s32 unkB6C4;
};

s32 func_0043AC68(s32 arg0) {
    s32 temp_v0;
    s32 temp_v1;
    struct func_0043AC68_temp_a0 *temp_a0;
    struct func_0043AC68_temp_v0_2 *temp_v0_2;

    temp_v0_2 = arg0 + 0x3A368;
    temp_a0 = arg0 + 0x568;
    temp_v1 = temp_v0_2->unkA58;
    temp_v0_2->unkA58 = 0;
    temp_v0 = temp_a0->unkB6C4;
    temp_a0->unkB6C4 = 0;
    return (temp_v1 != 0) | (temp_v0 != 0);
}
