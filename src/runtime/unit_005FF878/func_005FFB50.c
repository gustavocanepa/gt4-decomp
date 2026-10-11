/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005FFB50_arg0 {
    s128 unk0;
    s128 unk10;
    char pad20[0x10];
    s128 unk30;
    f32 unk40;
    f32 unk44;
};
struct func_005FFB50_arg1 {
    s128 unk0;
    s128 unk10;
    char pad20[0x10];
    s128 unk30;
    f32 unk40;
    f32 unk44;
};

void *func_005FFB50(struct func_005FFB50_arg0 *arg0, struct func_005FFB50_arg1 *arg1) {
    arg0->unk0 = (s128) arg1->unk0;
    arg0->unk10 = (s128) arg1->unk10;
    arg0->unk30 = (s128) arg1->unk30;
    arg0->unk40 = (f32) arg1->unk40;
    arg0->unk44 = (f32) arg1->unk44;
    return arg0;
}
