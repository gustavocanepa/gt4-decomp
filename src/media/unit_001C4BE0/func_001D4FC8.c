#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00427820(void *);                      /* extern */

struct func_001D4FC8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    char pad14[0x24];
    s32 unk38;
    s32 unk3C;
    char pad40[0x170];
    s32 unk1B0;
};

s32 func_001D4FC8(void *arg0) {
    ((struct func_001D4FC8_arg0 *)arg0)->unk0 = 0;
    ((struct func_001D4FC8_arg0 *)arg0)->unk4 = 0;
    ((struct func_001D4FC8_arg0 *)arg0)->unk8 = 0;
    ((struct func_001D4FC8_arg0 *)arg0)->unkC = 0;
    ((struct func_001D4FC8_arg0 *)arg0)->unk10 = 0;
    func_00427820(arg0 + 0x20);
    func_00427820(arg0 + 0x2C);
    ((struct func_001D4FC8_arg0 *)arg0)->unk38 = 0;
    ((struct func_001D4FC8_arg0 *)arg0)->unk3C = 0;
    ((struct func_001D4FC8_arg0 *)arg0)->unk1B0 = 1;
}
