typedef int s32;

struct Obj {
    char pad0[0x20];
    s32 unk20;
    char pad2[0x3C - 0x20 - 4];
    s32 unk3C;
};

extern "C" void RaceDisplay__virtual_07(Obj *arg0, s32 arg1) {
    arg0->unk20 = arg1;
    arg0->unk3C = (arg0->unk3C & 0xFFFFFF) | 0x1000000;
}
