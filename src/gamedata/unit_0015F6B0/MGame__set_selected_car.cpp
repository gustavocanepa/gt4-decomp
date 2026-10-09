typedef int s32;

extern "C" void *func_0015F3E0(void *);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(s32);

struct Sub {
    s32 pad[3];
    s32 c;
    s32 d;
    void setC(s32 v) { c = v; }
    void setD(s32 v) { d = v; }
};
struct Big {
    char pad[0x3A368];
    struct Sub sub;
};

extern "C" void func_002FC870(void *, s32);
extern "C" void func_0015F388(void *, s32);

extern "C" void MGame__set_selected_car(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    if (arg2 > 0) {
        func_0015F3E0(buf0);
        p_s1 = buf1;
        func_002FC8C8(p_s1, arg3);
        struct Big *b = *(struct Big **)((char *)buf0[0] + 0x10);
        b->sub.setD(func_002FE250(*p_s1));
        func_002FC870(p_s1, 0x2);
        func_0015F388(buf0, 0x2);
    }
}
