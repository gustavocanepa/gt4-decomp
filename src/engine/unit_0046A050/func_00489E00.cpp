typedef float f32;

struct Obj {
    f32 unk0;
    char pad1[0x14 - 0x0 - 4];
    f32 unk14;
    char pad2[0x28 - 0x14 - 4];
    f32 unk28;
    char pad3[0x3C - 0x28 - 4];
    f32 unk3C;
};

extern "C" f32 func_00489E00(Obj *arg0) {
    return arg0->unk0 + arg0->unk14 + arg0->unk28 + arg0->unk3C;
}
