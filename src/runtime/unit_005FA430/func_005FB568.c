#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FB568_arg0 {
    char pad0[0x18];
    f32 unk18;
};

void func_005FB568(struct func_005FB568_arg0 *arg0, f32 fparg0) {
    arg0->unk18 = fparg0;
}
