extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    VEntry *vt;
    char pad68[0x4];
    char lock[0x38];
    int refs;
};

extern "C" void func_0010ABB0(Obj *self, int arg)
{
    func_00576788(self->lock);
    if (self->refs < 2) {
        VEntry *e = &self->vt[18];
        e->fn((char *)self + e->delta, arg);
    }
    func_005767C0(self->lock);
}
