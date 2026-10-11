#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void AutomaticFader__reset(void *);
struct func_003AD580_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
    char pad20[0x1C];
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
};

void func_003AD580(s8 *arg0) {
    ((struct func_003AD580_arg0 *)arg0)->unk18 = 0;
    ((struct func_003AD580_arg0 *)arg0)->unk1C = 0;
    AutomaticFader__reset(arg0 + 0x20);
    ((struct func_003AD580_arg0 *)arg0)->unk3C = 0;
    ((struct func_003AD580_arg0 *)arg0)->unk40 = 0;
    ((struct func_003AD580_arg0 *)arg0)->unk44 = 0;
    ((struct func_003AD580_arg0 *)arg0)->unk48 = 0;
    ((struct func_003AD580_arg0 *)arg0)->unk4C = 0;
    ((struct func_003AD580_arg0 *)arg0)->unk50 = (s32) (((((struct func_003AD580_arg0 *)arg0)->unk50 & ~0xFF) | 1) & 0xFFFF00FF);
}
