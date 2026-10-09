typedef int s32;
typedef float f32;

struct VEntry {
    short delta;
    short index;
    f32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct Obj {
    char pad0[4];
};

extern "C" void func_00236680(void *arg0, int arg1);
extern "C" void func_002366D8(void *arg0, void *arg1);
extern "C" f32 func_00238FE8(Obj *arg0);
extern "C" void func_00238FF0(Obj *arg0, f32 v);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, float fparg0);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MScaleBar__get_repeat_start(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Obj *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        f32 f;
        func_002366D8(h, arg1);
        f = func_00238FE8(h[0]);
        buf0 = buf;
        func_002F9360(buf0, f);
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
        func_002F7B68(buf0, 2);
        func_00236680(h, 2);
    } else if (arg2 == 1) {
        func_002366D8(h, arg1);
        {
            Obj *hv = h[0];
            VObj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x60);
            func_00238FF0(hv, e->fn((char *)o + e->delta));
        }
        func_00236680(h, 2);
    }
}
