typedef int s32;
typedef float f32;

struct Arg1 {
    char pad0[8];
    s32 unk8;
};

extern "C" f32 func_00477460(s32 arg0);
extern "C" void func_00480FA0(Arg1 *arg0, s32 arg1);
extern "C" void func_0057D380(f32 arg0);

extern "C" void func_0047BD28(s32 arg0, Arg1 *arg1) {
    f32 var20;

    if (arg0 != 0) {
        var20 = func_00477460(arg1->unk8 - 8);
    } else {
        var20 = 0.0f;
    }
    func_00480FA0(arg1, arg0);
    func_0057D380(var20);
}
