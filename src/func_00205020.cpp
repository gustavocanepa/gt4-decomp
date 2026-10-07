typedef int s32;

extern "C" void func_00204D30(void *arg0, int arg1);
extern "C" void func_00204D88(void *arg0, void *arg1);
extern "C" s32 func_00206868(s32 arg0);
extern "C" void func_00309348(s32 *arg0, s32 *arg1);
extern "C" void func_00309378(s32 *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_00205020(s32 *arg0, void *arg1) {
    s32 buf1[4];
    s32 buf0[4];
    s32 temp;
    s32 newVal;
    s32 oldVal;

    func_00204D88(buf1, arg1);
    s32 *ptemp = &temp;
    temp = func_00206868(buf1[0]);
    s32 *p0 = buf0;
    func_00309348(p0, ptemp);
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
    func_00309378(p0, 2);
    func_00204D30(buf1, 2);
}
