typedef float f32;

struct Obj_00370070 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
    char pad1[0x1C - 0x10 - 4];
    f32 unk1C;
};

extern "C" f32 func_00370070(struct Obj_00370070 *arg0, f32 fparg0) {
    f32 a = arg0->unk8;

    return (a * fparg0) / ((arg0->unk1C * arg0->unk10 * a) / arg0->unkC);
}
