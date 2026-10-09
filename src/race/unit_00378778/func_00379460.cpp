typedef float f32;

struct Obj {
    char pad[0x14];
    f32 unk14;
    char pad2[0x80 - 0x14 - 4];
    f32 unk80;
};

extern "C" f32 func_00379460(Obj *arg0, f32 fparg0) {
    f32 a = arg0->unk14;
    return a + (arg0->unk80 - a) * fparg0;
}
