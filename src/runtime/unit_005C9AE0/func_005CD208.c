#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CD208_arg0_unk10 {
    char pad0[0x1694];
    s16 unk1694;
};
struct func_005CD208_arg0 {
    char pad0[0x10];
    struct func_005CD208_arg0_unk10 *unk10;
};

void func_005CD208(struct func_005CD208_arg0 *arg0, s16 arg1) {
    arg0->unk10->unk1694 = arg1;
}
