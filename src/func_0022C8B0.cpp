typedef int s32;

extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" void func_00231F60(s32 arg0, s32 arg1);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);

extern "C" void MRenderContext__set_popup_widget(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0 = arg3;

    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_0022AD20(buf0, (void *)arg1);
        s32 *p1 = buf1;
        func_00255110(p1, (void *)s0);
        func_00231F60(buf0[0], p1[0]);
        func_002550B8(p1, 2);
        func_0022ACC8(buf0, 2);
    }
}
