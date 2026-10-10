#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00689EE0[];
struct func_0057ACD8_arg0 {
    s32 unk0;
    char pad4[0xC];
    s32 unk10;
};

s32 func_0057ACD8(struct func_0057ACD8_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk10 = (s32)D_00689EE0;
}
