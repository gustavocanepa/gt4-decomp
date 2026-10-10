#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FE748_arg0 {
    char pad0[0x890];
    f32 unk890;
};

void func_005FE748(struct func_005FE748_arg0 *arg0, f32 fparg0) {
    arg0->unk890 = fparg0;
}
