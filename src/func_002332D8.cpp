typedef int s32;

extern "C" void func_00232C20(void *arg0, int arg1);
extern "C" void func_00232C78(void *arg0, void *arg1);
extern "C" s32 func_00235C00(s32 arg0);
extern "C" void func_00255088(s32 *arg0, s32 *arg1);
extern "C" void func_002550B8(s32 *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_002332D8(s32 *arg0, void *arg1) {
    s32 buf1[4];
    s32 buf0[4];
    s32 temp;
    s32 newVal;
    s32 oldVal;

    func_00232C78(buf1, arg1);
    s32 *ptemp = &temp;
    temp = func_00235C00(buf1[0]);
    s32 *p0 = buf0;
    func_00255088(p0, ptemp);
    if (arg0 != p0) {
        newVal = *p0;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002550B8(p0, 2);
    func_00232C20(buf1, 2);
}
