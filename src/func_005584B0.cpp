typedef int s32;
typedef float f32;

struct S005584B0 {
    char pad0[0x794];
    f32 unk794;
    s32 unk798;
};

extern "C" void func_00578480(s32 arg0);

extern "C" void func_005584B0(S005584B0 *arg0, f32 fparg0) {
    arg0->unk794 = fparg0;
    func_00578480(arg0->unk798);
}
