typedef int s32;
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}
extern "C" void func_002284D8(void *, void *);
extern "C" void func_00228480(void *, s32);
extern "C" void func_002289F8(void *, float);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void MProgress__set_value(void *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    float v = vcall_60(*arg3);
    func_002284D8(&a, arg1);
    func_002289F8(a.p, v);
    func_00228480(&a, 2);
}
