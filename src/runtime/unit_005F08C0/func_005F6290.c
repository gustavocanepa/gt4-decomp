#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F6290_arg0 {
    char pad0[0x1CC];
    f32 unk1CC;
};

void func_005F6290(struct func_005F6290_arg0 *arg0, f32 fparg0) {
    arg0->unk1CC = fparg0;
}
