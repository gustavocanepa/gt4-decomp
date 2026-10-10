typedef int s32;

extern "C" void func_0022AD20(void *, void *);
extern "C" s32 func_0022F350(s32);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_00255088(void *, s32 *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002550B8(void *, s32);

extern "C" void MRenderContext__getPrelightWidget(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v;
    s32 newVal;
    s32 oldVal;
    func_0022AD20(buf0, arg1);
    v = func_0022F350(buf0[0]);
    func_0022ACC8(buf0, 0x2);
    if (v == 0)
        return;
    buf1[0] = v;
    func_00255088(buf0, buf1);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002550B8(buf0, 0x2);
}
