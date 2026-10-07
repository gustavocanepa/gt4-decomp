typedef int s32;

struct Obj {
    char pad0[0x1C];
    s32 unk1C;
    char pad2[0x3C - 0x1C - 4];
    s32 unk3C;
};

extern "C" void func_0039B3A0(Obj *arg0, s32 arg1) {
    arg0->unk1C = arg1;
    arg0->unk3C = arg0->unk3C & 0xFF00FFFF;
}
