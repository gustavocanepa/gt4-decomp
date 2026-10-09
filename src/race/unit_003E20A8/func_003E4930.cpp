typedef int s32;
typedef float f32;

struct Struct003E4930 {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" void func_003E24F0(s32 arg0, f32 arg1, f32 arg2, f32 arg3);

extern "C" void func_003E4930(struct Struct003E4930 *arg0, s32 arg1) {
    func_003E24F0(arg1, arg0->unk4, arg0->unk8, arg0->unkC);
}
