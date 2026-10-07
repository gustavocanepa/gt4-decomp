typedef int s32;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_001240D8(void *arg0, int arg1);
extern "C" void func_00124130(void *arg0);
extern "C" s32 func_00127C10(s32 arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_00125108(s32 *arg0, s32 arg1, s32 n, Obj **args) {
    s32 tmp[4];
    s32 buf0[4];
    s32 *pb;
    s32 newVal;
    s32 oldVal;
    s32 v;
    func_00124130(tmp);
    v = 0;
    if (n > 0) {
        Obj *o = *args;
        VEntry *e = (VEntry *)(o->vtbl + 0x58);
        v = e->fn((char *)o + e->delta);
    }
    v = func_00127C10(tmp[0], v);
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
    func_001240D8(tmp, 2);
}
