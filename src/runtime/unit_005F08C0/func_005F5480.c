#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F5480_arg0 {
    char pad0[0xA80];
    s64 unkA80;
    s64 unkA88;
    s64 unkA90;
    s64 unkA98;
    s64 unkAA0;
    s64 unkAA8;
    s64 unkAB0;
    s64 unkAB8;
};
struct func_005F5480_arg1 {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
    s64 unk28;
    s64 unk30;
    s64 unk38;
};

void func_005F5480(struct func_005F5480_arg0 *arg0, struct func_005F5480_arg1 *arg1) {
    arg0->unkA80 = (s64) arg1->unk0;
    arg0->unkA88 = (s64) arg1->unk8;
    arg0->unkA90 = (s64) arg1->unk10;
    arg0->unkA98 = (s64) arg1->unk18;
    arg0->unkAA0 = (s64) arg1->unk20;
    arg0->unkAA8 = (s64) arg1->unk28;
    arg0->unkAB0 = (s64) arg1->unk30;
    arg0->unkAB8 = (s64) arg1->unk38;
}
