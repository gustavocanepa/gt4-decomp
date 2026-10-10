#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F5430_arg0 {
    char pad0[0xA40];
    s64 unkA40;
    s64 unkA48;
    s64 unkA50;
    s64 unkA58;
    s64 unkA60;
    s64 unkA68;
    s64 unkA70;
    s64 unkA78;
};
struct func_005F5430_arg1 {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
    s64 unk28;
    s64 unk30;
    s64 unk38;
};

void func_005F5430(struct func_005F5430_arg0 *arg0, struct func_005F5430_arg1 *arg1) {
    arg0->unkA40 = (s64) arg1->unk0;
    arg0->unkA48 = (s64) arg1->unk8;
    arg0->unkA50 = (s64) arg1->unk10;
    arg0->unkA58 = (s64) arg1->unk18;
    arg0->unkA60 = (s64) arg1->unk20;
    arg0->unkA68 = (s64) arg1->unk28;
    arg0->unkA70 = (s64) arg1->unk30;
    arg0->unkA78 = (s64) arg1->unk38;
}
