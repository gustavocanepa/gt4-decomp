extern "C" int HValue__isValid(void *handle);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int, void *);
};

struct Target {
    int pad0;
    VEntry *vt;
};

struct Obj {
    char pad0[0x14];
    char value[4];
    Target *target;
};

extern "C" void hModuleVariable__evaluate(Obj *self, int arg)
{
    HValue__isValid(&self->target);
    Target *t = self->target;
    VEntry *e = &t->vt[9];
    e->fn((char *)t + e->delta, arg, self->value);
}
