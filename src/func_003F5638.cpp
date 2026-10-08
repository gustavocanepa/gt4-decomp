typedef int s32;

extern "C" void func_0034CF30(void);

extern "C" void func_003F5638(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 *s0 = arg5;

    func_0034CF30();
    if (*s0 != 0) {
        *s0 = 2;
    }
}
