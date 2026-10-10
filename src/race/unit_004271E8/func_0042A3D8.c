#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0042A560();                                /* extern */

struct func_0042A3D8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_0042A3D8(struct func_0042A3D8_arg0 *arg0) {
    return arg0->unk4 + (func_0042A560() << 5);
}
