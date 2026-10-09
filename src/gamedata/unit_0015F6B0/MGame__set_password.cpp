typedef int s32;

extern "C" void func_00312370(void *, void *);
extern "C" void *func_0015F3E0(void *, void *);
extern "C" s32 func_00314AD8(s32);
extern "C" void func_0043AF28(s32, s32);
extern "C" void func_0015F388(void *, s32);
extern "C" void func_00312318(void *, s32);

extern "C" void MGame__set_password(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    func_00312370(buf0, arg3);
    p_s1 = buf1;
    func_0015F3E0(p_s1, arg1);
    v_s0 = *(s32 *)((char *)*p_s1 + 0x10) + 0x348;
    func_0043AF28(v_s0, func_00314AD8(buf0[0]));
    func_0015F388(p_s1, 0x2);
    func_00312318(buf0, 0x2);
}
