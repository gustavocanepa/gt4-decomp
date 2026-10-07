typedef unsigned char u8;
typedef float f32;

struct Obj {
    u8 unk0;
    u8 unk1;
    char pad2[2];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

extern "C" void func_00391EB0(Obj *arg0) {
    f32 zero = 0.0f;
    arg0->unk0 = 0;
    arg0->unk1 = 0;
    arg0->unk10 = zero;
    arg0->unkC = zero;
    arg0->unk8 = zero;
    arg0->unk4 = zero;
}
