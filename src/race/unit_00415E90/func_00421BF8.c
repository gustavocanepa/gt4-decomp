#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00421BF8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

f32 func_00421BF8(struct func_00421BF8_arg0 *arg0, f32 fparg0) {
    return (((arg0->unkC * fparg0 * arg0->unk8 * fparg0) + arg0->unk4) * fparg0) + arg0->unk0;
}
