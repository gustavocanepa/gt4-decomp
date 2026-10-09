typedef int s32;

extern "C" void *func_0015F3E0(void *);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);
extern "C" void func_00430888(s32, s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_0015F388(void *, s32);

extern "C" void MGame__set_manual_2p(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    if (arg2 > 0) {
        func_0015F3E0(buf0);
        p_s1 = buf1;
        func_002FC8C8(p_s1, arg3);
        v_s0 = *(s32 *)((char *)buf0[0] + 0x10) + 0x140;
        func_00430888(v_s0, func_002FE250(*p_s1) != 0);
        func_002FC870(p_s1, 0x2);
        func_0015F388(buf0, 0x2);
    }
}
