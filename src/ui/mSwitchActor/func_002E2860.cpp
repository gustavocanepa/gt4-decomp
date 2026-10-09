typedef float f32;

struct Obj {
    char pad[0x38];
    f32 unk38;
};

extern "C" void func_002E2860(Obj *arg0, f32 fparg0) {
    arg0->unk38 = 0.016666666f / fparg0;
}
