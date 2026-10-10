struct State {
    int v[5];
};

struct Target {
    char pad0[0x84];
    State state;
};

struct VEntry {
    short delta;
    short index;
    State (*fn)(void *, Target *);
};

struct Obj {
    char pad0[0xA4];
    VEntry *vt;
};

extern "C" void func_004B0BD8(Obj *self, Target *t)
{
    VEntry *e = &self->vt[25];
    State s = e->fn((char *)self + e->delta, t);
    t->state = s;
}
