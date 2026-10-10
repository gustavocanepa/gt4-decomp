#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052E510_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x50];
    s32 unk58;
    s32 unk5C;
};

s32 func_0052E510(struct func_0052E510_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        func_005A48D8(arg0, 0, 0x78);
        arg0->unk0 = 1;
        arg0->unk5C = 0xE4A;
        arg0->unk58 = 0;
        arg0->unk4 = -1;
        var_v0 = 0;
    }
    return var_v0;
}
