#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0030A798();                            /* extern */

struct func_002FE190_arg0 {
    u8 pad0[0x10];
    s32 unk10;
};
struct func_002FE190_arg1 {
    u8 pad0[0x10];
    s32 unk10;
};

void *func_002FE190(struct func_002FE190_arg0 *arg0, struct func_002FE190_arg1 *arg1) {
    if (arg0 != arg1) {
        func_0030A798();
        arg0->unk10 = (s32) arg1->unk10;
    }
    return arg0;
}
