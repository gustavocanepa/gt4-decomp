typedef int s32;

extern "C" void func_004F8E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_004F90F8(s32 arg0, s32 *arg1) {
    func_004F8E20(arg0, *arg1, 0, 0, 0);
}
