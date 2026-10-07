typedef int s32;

struct H {
    char pad0[0x10];
    s32 p10;
};

extern "C" void func_0015AA68(void *arg0, int arg1);
extern "C" void *func_0015AAC0(void *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" s32 func_00433470(s32 arg0);

static inline H *get(H **p) {
    return *p;
}

extern "C" void func_0015AD68(s32 *arg0) {
    H *tmp[4];
    s32 buf0[4];
    s32 *pb;
    s32 v;
    s32 newVal;
    s32 oldVal;
    func_0015AAC0(tmp);
    v = func_00433470(get(tmp)->p10);
    pb = buf0;
    func_002FE278(pb, v);
    if (arg0 != pb) {
        newVal = *pb;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(pb, 2);
    func_0015AA68(tmp, 2);
}
