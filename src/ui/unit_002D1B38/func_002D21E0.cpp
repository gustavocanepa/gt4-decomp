typedef float f32;
typedef int s32;

struct Obj_002D21E0 {
    char pad0[0xC];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    char pad1[0x20 - 0x14 - 4];
    s32 unk20;
};

extern "C" void func_002D2288(struct Obj_002D21E0 *arg0);

extern "C" void func_002D21E0(struct Obj_002D21E0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    if (arg0->unk20 != 0) {
        arg0->unkC = fparg0;
        arg0->unk10 = fparg2;
        arg0->unk14 = -fparg1;
        func_002D2288(arg0);
    }
}
