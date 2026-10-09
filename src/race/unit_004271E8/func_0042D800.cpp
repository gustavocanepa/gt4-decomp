typedef int s32;
typedef float f32;

struct Obj {
    s32 unk0;
    char pad[0x4];
    s32 unk8;
    f32 unkC;
};

extern "C" void func_0042D800(Obj *arg0, f32 fparg0) {
    arg0->unkC = fparg0;
    arg0->unk8 = 1;
    arg0->unk0 = 1;
}
