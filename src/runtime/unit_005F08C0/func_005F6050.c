#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F6050_arg0 {
    char pad0[0x1E8];
    f32 unk1E8;
};

f32 func_005F6050(struct func_005F6050_arg0 *arg0) {
    return arg0->unk1E8;
}
