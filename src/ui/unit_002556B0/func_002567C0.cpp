typedef int s32;

extern "C" void func_00255110(s32 *arg0);
extern "C" s32 func_0025C300(s32 arg0);
extern "C" void func_00309348(s32 *arg0, s32 *arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_00309378(s32 *arg0, s32 arg1);
extern "C" void func_002550B8(s32 *arg0, s32 arg1);

extern "C" void func_002567C0(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 temp;
    s32 *ptemp = &temp;
    s32 newVal;
    s32 oldVal;

    func_00255110(p1);
    temp = func_0025C300(*p1);
    func_00309348(buf0, ptemp);
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
    func_00309378(buf0, 2);
    func_002550B8(p1, 2);
}
