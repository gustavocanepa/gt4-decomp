#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041C078_arg0 {
    char pad0[0x50];
    s128 unk50;
};

void func_0041C078(struct func_0041C078_arg0 *arg0, s128 *arg1) {
    arg0->unk50 = (s128) *arg1;
}
