typedef float f32;

struct Obj00384E38 {
    char pad0[4];
    f32 unk4;
    char pad1[0x84 - 4 - 4];
    f32 unk84;
};

extern "C" f32 func_00384E38(struct Obj00384E38 *arg0) {
    return arg0->unk4 + (arg0->unk84 * 5.0f);
}
