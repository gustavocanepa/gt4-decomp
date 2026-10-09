typedef int s32;

extern "C" void func_0022AD20(s32 *arg0);
extern "C" s32 func_0022FB50(s32 arg0);
extern "C" void func_00232BF0(s32 *arg0, s32 *arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_00232C20(s32 *arg0, s32 arg1);
extern "C" void func_0022ACC8(s32 *arg0, s32 arg1);

extern "C" void MRenderContext__getCurrentPage(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 temp;
    s32 *ptemp = &temp;
    s32 newVal;
    s32 oldVal;

    func_0022AD20(p1);
    temp = func_0022FB50(*p1);
    func_00232BF0(buf0, ptemp);
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
    func_00232C20(buf0, 2);
    func_0022ACC8(p1, 2);
}
