typedef int s32;
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}
extern "C" void func_0017FB28(void *);
extern "C" void func_0017FAD0(void *, s32);
extern "C" void func_002F9360(void *, float);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F7B68(void *, s32);

struct Inner {
    char pad0[0x8C];
    s32 value;
};
struct Mid {
    char pad0[0x10];
    Inner *inner;
};
struct A {
    Mid *p;
    s32 pad[3];
};

extern "C" void MOption__get_slide_bgm_volume(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    s32 b[4];
    if (arg2 > 0) {
        func_0017FB28(&a);
        Mid *m = a.p;
        float f = vcall_60(*arg3);
        m->inner->value = (s32)(f * 128.0f);
        func_0017FAD0(&a, 2);
    } else {
        func_0017FB28(&a);
        s32 *pb = b;
        func_002F9360(pb, (float)a.p->inner->value * 0.0078125f);
        if (arg0 != pb) {
            s32 newVal = pb[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            s32 oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(pb, 2);
        func_0017FAD0(&a, 2);
    }
}
