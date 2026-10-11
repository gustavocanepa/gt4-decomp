#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FD860_arg0 {
    char pad0[0x1E670];
    f32 unk1E670;
};

void func_005FD860(struct func_005FD860_arg0 *arg0, f32 fparg0) {
    arg0->unk1E670 = fparg0;
}
