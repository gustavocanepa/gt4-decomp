typedef int s32;
typedef float f32;

extern f32 D_00623874;
extern "C" void func_004A4550(s32, s32);

extern "C" void func_00343170(void *self, s32 on) {
    s32 i = -10;
    f32 v;
    if (on) i = 0;
    v = (f32)i;
    D_00623874 = v;
    func_004A4550(10, (s32)(v * 0x1.000000p+8f));
}
