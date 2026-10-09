typedef float f32;

struct Obj {
    char pad[0x1C];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};

extern "C" void func_00378F18(Obj *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    arg0->unk1C = fparg0;
    arg0->unk20 = fparg1;
    arg0->unk24 = fparg2;
}
