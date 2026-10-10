#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_00450040_temp_a2 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

void *func_00450040(void **arg0, s32 arg1) {
    void *temp_a2;

    temp_a2 = *arg0;
    return temp_a2 + ((M2C_FIELD(((arg1 * 4) + temp_a2), s32 *, 0x10) & ~((struct func_00450040_temp_a2 *)temp_a2)->unkC) + ((struct func_00450040_temp_a2 *)temp_a2)->unk8);
}
