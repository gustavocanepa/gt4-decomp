typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
    f32 unkC;
    f32 unk10;
};

extern "C" void func_0047CFA0(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk8 = 1;
    arg0->unk10 = fparg1;
    arg0->unkC = fparg0;
}
