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

extern "C" void func_002CC8C8(void *arg0, int arg1);
extern "C" void func_002CC920(void *arg0, void *arg1);
extern "C" f32 func_002CDB18(s32 arg0);
extern "C" void func_002CDB20(s32 arg0, f32 v);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, float fparg0);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MRotateActor__get_ratio(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    s32 buf0[4];
    if (arg2 > 0) {
        f32 f;
        {
            VObj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x60);
            f = e->fn((char *)o + e->delta);
        }
        func_002CC920(buf0, arg1);
        func_002CDB20(buf0[0], f);
        func_002CC8C8(buf0, 2);
    } else {
        s32 buf1[4];
        s32 *p1 = buf1;
        s32 newVal;
        s32 oldVal;
        func_002CC920(p1, arg1);
        func_002F9360(buf0, func_002CDB18(*p1));
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
        func_002CC8C8(p1, 2);
    }
}
