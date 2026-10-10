#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0044E380_arg0 {
    u8 pad0[0x18];
    f32 unk18;
    f32 unk1C;
};

void func_0044E380(struct func_0044E380_arg0 *arg0, f32 fparg0) {
    arg0->unk18 = fparg0;
    arg0->unk1C = fparg0;
}
