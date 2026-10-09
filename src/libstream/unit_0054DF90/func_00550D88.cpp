typedef int s32;

extern "C" void func_00550C68(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern char D_0086F800[];

extern "C" void func_00550D88(s32 arg0, s32 arg1, s32 arg2) {
    func_00550C68(D_0086F800, 4, arg0, arg1, arg2);
}
