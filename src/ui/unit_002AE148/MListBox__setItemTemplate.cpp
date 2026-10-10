typedef int s32;

extern "C" void func_002AE9C0(void *, void *);
extern "C" void func_0022AD20(void *, s32 *);
extern "C" void func_00255088(void *, s32 *);
extern "C" void func_002B48F0(s32, s32, s32);
extern "C" void func_002550B8(void *, s32);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_002AE968(void *, s32);

extern "C" void MListBox__setItemTemplate(s32 *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s1;
    s32 *p_s0;
    s32 *p_v0;
    if (arg2 == 0x2) {
        func_002AE9C0(buf0, arg1);
        p_s1 = buf1;
        func_0022AD20(p_s1, arg3);
        p_v0 = buf3;
        p_s0 = buf2;
        *p_v0 = arg3[1];
        func_00255088(p_s0, p_v0);
        func_002B48F0(buf0[0], *p_s1, *p_s0);
        func_002550B8(p_s0, 0x2);
        func_0022ACC8(p_s1, 0x2);
        func_002AE968(buf0, 0x2);
    }
}
