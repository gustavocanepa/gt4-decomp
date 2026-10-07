typedef int s32;

extern "C" void func_0057B210(s32 arg0, s32 arg1, s32 *arg2);

extern "C" s32 func_0057B1E8(s32 arg0, s32 arg1, s32 arg2) {
    s32 local = arg2;
    func_0057B210(arg0, arg1, &local);
    return local;
}
