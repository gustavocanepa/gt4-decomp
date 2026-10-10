struct Part { char pad[0xD4]; char mD4[4]; };
struct VEntry {
    short delta;
    short index;
    Part *(*fn)(void *, int);
};
struct VObj {
    char pad[0x64];
    VEntry *vtbl;
};
static inline Part *vcall72(VObj *o, int id)
{
    VEntry *e = &o->vtbl[72];
    return e->fn((char *)o + e->delta, id);
}
extern "C" int func_00346FC0(void *p, int n);

extern "C" int func_00330480(VObj *o)
{
    int a = func_00346FC0(vcall72(o, 0x100)->mD4, 1);
    int b = func_00346FC0(vcall72(o, 0x101)->mD4, 1);
    return a + b;
}
