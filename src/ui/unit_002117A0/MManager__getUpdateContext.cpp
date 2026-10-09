typedef int s32;

extern "C" void func_00211408(void *arg0, int arg1);
extern "C" void func_00211460(void *arg0, void *arg1);
extern "C" s32 func_00213158(s32 arg0);
extern "C" void func_0024E348(s32 *arg0, s32 *arg1);
extern "C" void func_0024E378(s32 *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MManager__getUpdateContext(s32 *arg0, void *arg1) {
    s32 buf1[4];
    s32 buf0[4];
    s32 temp;
    s32 newVal;
    s32 oldVal;

    func_00211460(buf1, arg1);
    s32 *ptemp = &temp;
    temp = func_00213158(buf1[0]);
    s32 *p0 = buf0;
    func_0024E348(p0, ptemp);
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
    func_0024E378(p0, 2);
    func_00211408(buf1, 2);
}
