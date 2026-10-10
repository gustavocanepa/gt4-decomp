#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char MenuControl__vtable[];
struct RaceInputLan {
    char unk_0[0xC8];
    void * unkC8;
    char unk_CC[0x4];
    void * unkD0;
    char unk_D4[0x70];
    s32 unk144;
    s32 unk148;
    s32 unk14C;
    char unk_150[0x44];
    s32 unk194;
    s32 unk198;
    s32 unk19C;
    char unk_1A0[0x24];
    s32 unk1C4;
    s32 unk1C8;
    s32 unk1CC;
    s32 unk1D0;
    s32 unk1D4;
    s32 unk1D8;
    s32 unk1DC;
    s32 unk1E0;
};
s32 func_005C1628(struct RaceInputLan *);       /* extern */

void MenuControl__structor_1(struct RaceInputLan *arg0, s32 arg1) {
    arg0->unkD0 = (void *)(s32)MenuControl__vtable;
    func_0055F738(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
