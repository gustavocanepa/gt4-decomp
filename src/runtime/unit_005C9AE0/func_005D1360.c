#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005D1360_arg0 {
    char pad0[0x8];
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
    s64 unk28;
    s64 unk30;
    s64 unk38;
    s64 unk40;
};
struct func_005D1360_arg1 {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
    s64 unk28;
    s64 unk30;
    s64 unk38;
};

void func_005D1360(struct func_005D1360_arg0 *arg0, struct func_005D1360_arg1 *arg1) {
    arg0->unk8 = (s64) arg1->unk0;
    arg0->unk10 = (s64) arg1->unk8;
    arg0->unk18 = (s64) arg1->unk10;
    arg0->unk20 = (s64) arg1->unk18;
    arg0->unk28 = (s64) arg1->unk20;
    arg0->unk30 = (s64) arg1->unk28;
    arg0->unk38 = (s64) arg1->unk30;
    arg0->unk40 = (s64) arg1->unk38;
}
