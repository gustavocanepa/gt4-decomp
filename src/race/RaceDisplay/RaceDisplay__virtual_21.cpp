typedef int s32;

struct Obj {
    char pad0[0x44];
    s32 unk44;
    char pad48[4];
    s32 unk4C;
};

extern "C" void RaceDisplay__virtual_21(Obj *arg0, s32 arg1) {
    if (arg0->unk4C != arg1) {
        arg0->unk4C = arg1;
        arg0->unk44 = (arg0->unk44 & ~0xFF) | 1;
    }
}
