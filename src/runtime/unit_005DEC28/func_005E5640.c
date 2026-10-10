#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E5640_arg0 {
    char pad0[0x30];
    f32 unk30;
};

void func_005E5640(struct func_005E5640_arg0 *arg0, f32 fparg0) {
    arg0->unk30 = fparg0;
}
