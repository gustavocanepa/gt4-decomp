#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F8C78_arg0 {
    char pad0[0x54];
    u8 unk54;
    u8 unk55;
};

void func_005F8C78(struct func_005F8C78_arg0 *arg0) {
    arg0->unk55 = (u8) arg0->unk54;
}
