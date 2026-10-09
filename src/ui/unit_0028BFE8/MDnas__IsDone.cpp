typedef int s32;

extern "C" void func_0028BD50(void *arg0, int arg1);
extern "C" void func_0028BDA8(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" s32 func_0032EE80(char *arg0);

extern "C" void MDnas__IsDone(s32 *arg0, void *arg1) {
    s32 buf0[4];
    char *buf1[4];
    char **p1 = buf1;
    s32 newVal;
    s32 oldVal;
    func_0028BDA8(p1, arg1);
    func_002FE278(buf0, func_0032EE80(*p1 + 0x10) != 0);
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
    func_002FC870(buf0, 2);
    func_0028BD50(p1, 2);
}
