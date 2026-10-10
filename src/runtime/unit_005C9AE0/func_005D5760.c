#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005D5760_arg0 {
    char pad0[0x1C];
    f32 unk1C;
};

void func_005D5760(struct func_005D5760_arg0 *arg0, f32 fparg0) {
    arg0->unk1C = fparg0;
}
