typedef int s32;

extern s32 D_0064C3C8;
extern s32 D_0086CBBC;
extern "C" void func_00578500(s32);
extern "C" void func_00578480(s32);

extern "C" s32 func_00548750(void) {
    s32 *lock = &D_0064C3C8;
    s32 r;
    func_00578500(*lock);
    r = D_0086CBBC;
    func_00578480(*lock);
    return r;
}
