#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0036A048_arg0 {
    char pad0[0x94];
    f32 unk94;
};
struct func_0036A048_arg1 {
    char pad0[0x94];
    f32 unk94;
};
struct func_0036A048_arg2 {
    char pad0[0x30];
    f32 unk30;
};

f32 func_0036A048(struct func_0036A048_arg0 *arg0, struct func_0036A048_arg1 *arg1, struct func_0036A048_arg2 *arg2) {
    f32 temp_f0;
    f32 temp_f1;

    temp_f1 = arg0->unk94 - arg1->unk94;
    temp_f0 = arg2->unk30;
    if (temp_f1 >= 0.0f) {
        return temp_f0 * temp_f1 * temp_f1;
    }
    return -temp_f0 * temp_f1 * temp_f1;
}
