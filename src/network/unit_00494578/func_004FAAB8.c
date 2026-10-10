#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004FAAB8_arg0 {
    char pad0[0xFD0];
    s32 unkFD0;
};

void func_004FAAB8(struct func_004FAAB8_arg0 *arg0) {
    arg0->unkFD0 = (s32) (arg0->unkFD0 + 1);
}
