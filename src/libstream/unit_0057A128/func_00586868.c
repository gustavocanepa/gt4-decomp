#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00586868_arg0 {
    char pad0[0x16];
    u16 unk16;
};

void func_00586868(struct func_00586868_arg0 *arg0) {
    arg0->unk16 = (u16) (arg0->unk16 | 1);
}
