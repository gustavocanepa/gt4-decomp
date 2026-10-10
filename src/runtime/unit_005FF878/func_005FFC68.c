/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005FFC68_arg0 {
    s128 unk0;
    s128 unk10;
    char pad20[0x10];
    s128 unk30;
    f32 unk40;
    f32 unk44;
    char pad48[0x8];
    s128 unk50;
    s128 unk60;
};
struct func_005FFC68_arg1 {
    s128 unk0;
    s128 unk10;
    char pad20[0x10];
    s128 unk30;
    f32 unk40;
    f32 unk44;
    char pad48[0x8];
    s128 unk50;
    s128 unk60;
};

void *func_005FFC68(struct func_005FFC68_arg0 *arg0, struct func_005FFC68_arg1 *arg1) {
    arg0->unk0 = (s128) arg1->unk0;
    arg0->unk10 = (s128) arg1->unk10;
    arg0->unk30 = (s128) arg1->unk30;
    arg0->unk40 = (f32) arg1->unk40;
    arg0->unk44 = (f32) arg1->unk44;
    arg0->unk50 = (s128) arg1->unk50;
    arg0->unk60 = (s128) arg1->unk60;
    return arg0;
}
