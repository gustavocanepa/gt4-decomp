typedef float f32;

struct Vec3 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct Src {
    char pad[0xC];
    f32 unkC;
};

extern "C" Vec3 *func_00459AB8(Vec3 *arg0, Src *arg1) {
    f32 z = 0.0f;
    arg0->unk0 = arg1->unkC;
    arg0->unk4 = z;
    arg0->unk8 = z;
    return arg0;
}
