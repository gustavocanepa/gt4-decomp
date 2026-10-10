#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FF900_arg0 {
    char pad0[0x70];
    f32 unk70;
};

void func_005FF900(struct func_005FF900_arg0 *arg0, f32 fparg0) {
    arg0->unk70 = fparg0;
}
