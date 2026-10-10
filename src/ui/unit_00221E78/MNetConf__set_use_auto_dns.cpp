extern "C" void func_00221B28(void *);
extern "C" void func_00221AD0(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct VEntry { short delta; short index; void (*fn)(void *, int); };
struct VObj { char pad0[4]; char *vtbl; };

struct A {
    VObj *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline int get(B *b) { return b->v[0]; }

extern "C" void MNetConf__set_use_auto_dns(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00221B28(&a);
        func_002FC8C8(&b, name);
        VObj *o = a.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x1A8);
        char *self = (char *)o + e->delta;
        int arg = func_002FE250(get(&b)) != 0;
        e->fn(self, arg);
        func_002FC870(&b, 2);
        func_00221AD0(&a, 2);
    }
}
