#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F8F78_arg0 {
    char pad0[0x20];
    f32 unk20;
};

void func_005F8F78(struct func_005F8F78_arg0 *arg0, f32 fparg0) {
    arg0->unk20 = fparg0;
}
