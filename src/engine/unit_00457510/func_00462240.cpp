typedef float f32;

extern char D_00846918[];

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_00461D78(f32 v);

extern "C" void func_00462240(f32 v) {
    func_00576788(D_00846918);
    func_00461D78(v);
    func_005767C0(D_00846918);
}
