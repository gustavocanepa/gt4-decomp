#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00613C28_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_00613C28(struct func_00613C28_arg0 *arg0) {
    return arg0->unk4 - arg0->unk0;
}
