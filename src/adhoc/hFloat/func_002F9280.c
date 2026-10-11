#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0030A798();                            /* extern */

struct func_002F9280_arg0 {
    u8 pad0[0x10];
    f32 unk10;
};
struct func_002F9280_arg1 {
    u8 pad0[0x10];
    f32 unk10;
};

void *func_002F9280(struct func_002F9280_arg0 *arg0, struct func_002F9280_arg1 *arg1) {
    if (arg0 != arg1) {
        func_0030A798();
        arg0->unk10 = (f32) arg1->unk10;
    }
    return arg0;
}
