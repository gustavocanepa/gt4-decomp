typedef int s32;

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" s32 func_0058CE88(void);

extern "C" char D_0064C880[];

extern "C" s32 func_00552640(void) {
    s32 s1;

    func_00576788(D_0064C880);
    s1 = func_0058CE88();
    func_005767C0(D_0064C880);
    return s1;
}
