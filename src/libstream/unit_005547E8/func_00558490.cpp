typedef int s32;
typedef float f32;

struct S00558490 {
    char pad0[0x790];
    f32 unk790;
    char pad1[0x798 - 0x794];
    s32 unk798;
};

extern "C" void func_00578480(s32 arg0);

extern "C" void func_00558490(S00558490 *arg0, f32 fparg0) {
    arg0->unk790 = fparg0;
    func_00578480(arg0->unk798);
}
