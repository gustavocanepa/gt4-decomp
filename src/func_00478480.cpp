/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Val;
extern "C" f32 func_00477460(Val *v);
extern "C" void func_00476BC0(Val *v, s32 n);

extern "C" void func_00478480(Val *a, Val *b) {
    f32 x = func_00477460(a);
    f32 y = func_00477460(b);
    func_00476BC0(a, (s32)x & (s32)y);
}
