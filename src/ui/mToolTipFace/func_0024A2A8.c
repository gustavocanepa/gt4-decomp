#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0024A2A8_arg0 {
    char pad0[0x110];
    s32 unk110;
};

f32 func_0024A2A8(struct func_0024A2A8_arg0 *arg0, f32 fparg0) {
    if (arg0->unk110 != 0) {
        return (2.0f * fparg0) / 60.0f;
    }
    return fparg0 / 60.0f;
}
