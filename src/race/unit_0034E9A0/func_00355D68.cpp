typedef float f32;

struct Obj {
    char pad[0x788];
    f32 unk788;
};

extern f32 D_008438DC;

extern "C" void func_00355D68(Obj *arg0, f32 fparg0) {
    arg0->unk788 = fparg0 * D_008438DC;
}
