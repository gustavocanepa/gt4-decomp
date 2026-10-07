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

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0);
extern "C" s32 func_00147D80(s32 arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" s32 func_0043F1F8(s32 arg0);
extern "C" s32 func_0043F220(s32 arg0);

extern "C" void func_0014D480(s32 *arg0, s32 arg1, s32 n, Obj **args) {
    s32 buf[4];
    s32 h;
    s32 r;
    s32 v;
    s32 newVal;
    s32 oldVal;
    func_0013BDC0(buf);
    h = func_00147D80(buf[0]);
    func_0013BD68(buf, 2);
    {
        Obj *o = *args;
        VEntry *e = (VEntry *)(o->vtbl + 0x58);
        r = e->fn((char *)o + e->delta);
    }
    switch (r) {
    case 0:
        v = func_0043F1F8(h);
        break;
    case 1:
        v = func_0043F220(h);
        break;
    default:
        v = -1;
        break;
    }
    func_002FE278(buf, v);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(buf, 2);
}
