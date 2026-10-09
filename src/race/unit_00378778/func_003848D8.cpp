typedef float f32;

struct Src_003848D8 {
    char pad[0x1C];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};

struct Obj_003848D8 {
    char pad[0x184];
    f32 unk184;
    char pad2[0x18C - 0x188];
    f32 unk18C;
    f32 unk190;
};

extern "C" void func_003848D8(Obj_003848D8 *arg0, Src_003848D8 *arg1) {
    arg0->unk184 = arg1->unk20;
    arg0->unk18C = arg1->unk24;
    arg0->unk190 = 2.0f / arg1->unk1C;
}
