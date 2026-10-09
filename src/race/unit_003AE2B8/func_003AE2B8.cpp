typedef int s32;
typedef float f32;

struct S003AE2B8 {
    char pad0[0x18];
    f32 unk18;
};

extern "C" void func_003AE2B8(S003AE2B8 *arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk18 = 1.0f;
        return;
    }
    arg0->unk18 = 0.0f;
}
