#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004CF298_arg0 {
    char pad0[0x4];
    void *unk4;
};

void func_004CF298(struct func_004CF298_arg0 *arg0) {
    arg0->unk4 = arg0;
}
