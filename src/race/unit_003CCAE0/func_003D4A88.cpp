typedef float f32;
typedef int s32;

struct Obj {
    char pad0[0x4C];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

extern "C" void func_003D4A88(Obj *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    if (arg1 == 0) {
        arg0->unk4C = fparg0;
        arg0->unk50 = fparg1;
    } else {
        arg0->unk54 = fparg0;
        arg0->unk58 = fparg1;
    }
}
