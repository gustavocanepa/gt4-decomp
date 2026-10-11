#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00603D68_arg0 {
    char pad0[0x58];
    f32 unk58;
};

f32 func_00603D68(struct func_00603D68_arg0 *arg0) {
    return arg0->unk58;
}
