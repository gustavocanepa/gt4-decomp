typedef int s32;

extern "C" void func_00565BA8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4);

extern "C" s32 func_00566FF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 local;
    func_00565BA8(arg0, arg1, arg2, arg3, &local);
    return local;
}
