#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00279840_arg0 {
    char pad0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
};

f32 func_00279840(struct func_00279840_arg0 *arg0) {
    return (arg0->unk34 - arg0->unk38) / (arg0->unk30 * 60.0f);
}
