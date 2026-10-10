#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_003D8B00_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
    char pad30[0x44];
    s32 unk74;
    s32 unk78;
};

f32 func_003D8B00(struct func_003D8B00_arg0 *arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk28;
    if ((temp_v1 == 1) && (arg0->unk2C == temp_v1)) {
        return (f32) (arg0->unk74 * arg0->unk78);
    }
    return 1.0f;
}
