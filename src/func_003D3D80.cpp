typedef float f32;

struct Inner {
    f32 unk0;
    f32 unk4;
};

struct Obj {
    char pad[0x44];
    Inner unk44;
    char pad2[0x70 - 0x44 - 8];
    f32 unk70;
};

extern "C" void func_003D3D80(Obj *arg0) {
    f32 zero = 0.0f;
    Inner *v0 = &arg0->unk44;
    v0->unk0 = zero;
    v0->unk4 = zero;
    arg0->unk70 = zero;
}
