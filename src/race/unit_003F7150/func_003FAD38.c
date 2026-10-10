#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FAD38_arg0 {
    s32 unk0;
    void *unk4;
    char pad8[0xC];
    s32 unk14;
};
struct func_003FAD38_temp_v0 {
    char pad0[0x1C4];
    s32 unk1C4;
};

void func_003FAD38(struct func_003FAD38_arg0 *arg0) {
    struct func_003FAD38_temp_v0 *temp_v0;

    func_003FABA0((s32) arg0, arg0->unk0, 0);
    temp_v0 = arg0->unk4;
    if (temp_v0 != NULL) {
        arg0->unk14 = (s32) temp_v0->unk1C4;
    }
}
