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

extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" s32 func_002662A0(s32 arg0);
extern "C" void func_002662B0(s32 arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_00257CE0(s32 *arg0, void *arg1, s32 arg2, Obj **arg3) {
    s32 buf0[4];
    if (arg2 == 0) {
        s32 buf1[4];
        s32 *p1 = buf1;
        s32 newVal;
        s32 oldVal;

        func_00255110(p1, arg1);
        func_002FE278(buf0, func_002662A0(*p1) != 0);
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
        func_002550B8(p1, 2);
    } else if (arg2 == 1) {
        Obj *o = *arg3;
        VEntry *e = (VEntry *)(o->vtbl + 0x58);
        s32 flag = e->fn((char *)o + e->delta) != 0;
        func_00255110(buf0, arg1);
        func_002662B0(buf0[0], flag);
        func_002550B8(buf0, 2);
    }
}
