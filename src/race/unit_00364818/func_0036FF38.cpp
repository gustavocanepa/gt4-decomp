typedef float f32;

struct Obj0036FF38 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
    char pad1[0x8];
    f32 unk1C;
};

extern "C" f32 func_0036FF38(struct Obj0036FF38 *arg0, f32 fparg0) {
    f32 temp_f3 = arg0->unk8;

    return (((arg0->unk1C * arg0->unk10 * temp_f3) / arg0->unkC) * fparg0) / temp_f3;
}
