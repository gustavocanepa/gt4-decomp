typedef int s32;

struct Big {
    char pad0[0x3A374];
    s32 v;
};

struct H {
    char pad0[0x10];
    Big *p10;
};

extern "C" void func_0015F388(void *arg0, int arg1);
extern "C" void func_0015F3E0(void *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_00161D58(s32 *arg0) {
    H *tmp[4];
    s32 buf0[4];
    s32 *pb;
    s32 newVal;
    s32 oldVal;
    func_0015F3E0(tmp);
    pb = buf0;
    func_002FE278(pb, tmp[0]->p10->v);
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
    func_0015F388(tmp, 2);
}
