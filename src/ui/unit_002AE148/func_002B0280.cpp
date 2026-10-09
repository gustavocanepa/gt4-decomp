typedef int s32;

extern "C" void func_002AE968(void *arg0, int arg1);
extern "C" void func_002AE9C0(void *arg0, void *arg1);
extern "C" void func_002B47E0(void *arg0, char *arg1);
extern "C" void func_002B4810(char *arg0, void *arg1);
extern "C" void func_002F9B38(void *arg0, int arg1);
extern "C" void func_002F9B90(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_002B0280(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    char *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        func_002AE9C0(h, arg1);
        buf0 = buf;
        func_002B47E0(buf0, h[0]);
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
        func_002F9B38(buf0, 2);
        func_002AE968(h, 2);
    } else if (arg2 == 1) {
        s32 buf2[4];
        s32 *p2;
        func_002AE9C0(h, arg1);
        p2 = buf2;
        func_002F9B90(p2, arg3);
        func_002B4810(h[0], p2);
        func_002F9B38(p2, 2);
        func_002AE968(h, 2);
    }
}
