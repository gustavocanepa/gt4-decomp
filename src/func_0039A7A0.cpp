typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x20];
    s32 unk20;
    f32 unk24;
    f32 unk28;
};

extern "C" void func_0039A7A0(Obj *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    arg0->unk20 = arg1;
    arg0->unk24 = fparg0;
    arg0->unk28 = fparg1;
}
