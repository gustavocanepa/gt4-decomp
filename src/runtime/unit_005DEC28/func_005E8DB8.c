#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E8DB8_arg0 {
    char pad0[0x50];
    f32 unk50;
};

void func_005E8DB8(struct func_005E8DB8_arg0 *arg0, f32 fparg0) {
    arg0->unk50 = fparg0;
}
