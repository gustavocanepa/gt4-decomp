#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00416EB0_arg0 {
    char pad0[0x210];
    f32 unk210;
    f32 unk214;
    f32 unk218;
    char pad21C[0x134];
    f32 unk350;
};

f32 func_00416EB0(struct func_00416EB0_arg0 *arg0) {
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;

    temp_f4 = arg0->unk350;
    if ((temp_f4 >= 0.0f) && (temp_f4 <= 1.0f)) {
        return (arg0->unk210 * (1.0f - temp_f4)) + (arg0->unk214 * temp_f4);
    }
    if (temp_f4 <= 2.0f) {
        temp_f2 = temp_f4 - 1.0f;
        return (arg0->unk214 * (1.0f - temp_f2)) + (arg0->unk218 * temp_f2);
    }
    if (temp_f4 <= 3.0f) {
        temp_f3 = temp_f4 - 2.0f;
        return (arg0->unk218 * (1.0f - temp_f3)) + (arg0->unk210 * temp_f3);
    }
    return 0.0f;
}
