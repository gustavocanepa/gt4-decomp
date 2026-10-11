#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00605038_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00605038(struct func_00605038_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = 1;
}
