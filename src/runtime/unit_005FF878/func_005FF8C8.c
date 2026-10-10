#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FF8C8_arg0 {
    char pad0[0x50];
    s128 unk50;
};

void func_005FF8C8(struct func_005FF8C8_arg0 *arg0, s128 *arg1) {
    arg0->unk50 = (s128) *arg1;
}
