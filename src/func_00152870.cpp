typedef int s32;
struct VEntry_58 { short delta; short index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern "C" void func_00151888(void *, void *);
extern "C" void func_00151830(void *, s32);
extern "C" void func_00154330(void *, s32);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_00152870(void *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    s32 v = vcall_58(*arg3) != 0;
    func_00151888(&a, arg1);
    func_00154330(a.p, v);
    func_00151830(&a, 2);
}
