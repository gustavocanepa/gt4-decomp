/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005722A8_arg0 {
    char pad0[0x4];
    u32 unk4;
};
struct func_005722A8_temp_a0 {
    void *unk0;
    u32 unk4;
};

struct func_005722A8_arg1 {
    char pad0[0x4];
    u32 unk4;
};

void *func_005722A8(struct func_005722A8_arg0 *arg0, void *arg1, s32 arg2) {
    u32 temp_a3;
    struct func_005722A8_temp_a0 *temp_a0;

    temp_a0 = arg1 + arg2;
    temp_a3 = ((struct func_005722A8_arg1 *)arg1)->unk4;
    if (temp_a3 < (u32) arg0->unk4) {
        *(s32 *)temp_a3 = temp_a0;
    }
    temp_a0->unk4 = temp_a3;
    ((struct func_005722A8_arg1 *)arg1)->unk4 = (u32) temp_a0;
    temp_a0->unk0 = arg1;
    return temp_a0;
}
