typedef int s32;

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" s32 func_0058CF08(void);

extern "C" char D_0064C880[];

extern "C" s32 func_005525F0(void) {
    s32 s1;

    func_00576788(D_0064C880);
    s1 = func_0058CF08();
    func_005767C0(D_0064C880);
    return s1;
}
