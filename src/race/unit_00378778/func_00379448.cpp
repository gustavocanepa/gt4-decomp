typedef float f32;

struct Obj {
    char pad[0x10];
    f32 unk10;
    char pad2[0x7C - 0x10 - 4];
    f32 unk7C;
};

extern "C" f32 func_00379448(Obj *arg0, f32 fparg0) {
    f32 a = arg0->unk10;
    return a + (arg0->unk7C - a) * fparg0;
}
