#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004B5CC0_arg0 {
    char pad0[0x858];
    s32 unk858;
};
struct func_004B5CC0_temp_v0 {
    char pad0[0x418];
    s32 unk418;
};

void *func_004B5CC0(void *arg0) {
    void *temp_v0;

    temp_v0 = arg0 + ((1 - ((struct func_004B5CC0_arg0 *)arg0)->unk858) * 0x41C) + 0x20;
    return temp_v0 + (((struct func_004B5CC0_temp_v0 *)temp_v0)->unk418 * 8) + 0x218;
}
