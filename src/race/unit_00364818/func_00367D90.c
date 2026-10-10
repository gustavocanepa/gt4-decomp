#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00367D90_arg0 {
    char pad0[0x13];
    s8 unk13;
    char pad14[0x1A];
    u16 unk2E;
};

void func_00367D90(struct func_00367D90_arg0 *arg0) {
    u16 temp_v0;

    temp_v0 = arg0->unk2E;
    if (temp_v0 >= 0x1388U) {
        arg0->unk13 = 3;
        return;
    }
    if (temp_v0 >= 0x1194U) {
        arg0->unk13 = 2;
        return;
    }
    arg0->unk13 = 1;
}
