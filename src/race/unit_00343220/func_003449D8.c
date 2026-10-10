#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003449D8_arg0 {
    char pad0[0x554];
    f32 unk554;
    char pad558[0x11C];
    f32 unk674;
    char pad678[0x24C];
    f32 unk8C4;
};

f32 func_003449D8(struct func_003449D8_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8C4 * temp_f12) + (arg0->unk674 * (1.0f - temp_f12));
}
