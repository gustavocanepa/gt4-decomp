typedef int s32;
typedef float f32;

extern "C" void func_002FFB58(s32 arg0, s32 arg1);

extern "C" s32 func_002FFCA8(s32 arg0, f32 arg1) {
    s32 s0 = arg0;
    union { f32 f; s32 i; } u;
    u.f = arg1;
    func_002FFB58(s0, u.i);
    return s0;
}
