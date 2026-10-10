struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int, int);
};

struct func_003A2130_Obj {
    VEntry *vtbl;
    char pad0[0x20 - 4];
    int f20;
    char pad1[0x5C - 0x24];
    int f5c;
    int f60;
};

extern "C" void RaceDisplay__setObjectDisplaySwitch(func_003A2130_Obj *self, unsigned int k, int v) {
    switch (k) {
    case 1:
    case 3:
    case 4:
        break;
    case 0:
        self->f5c = v;
        break;
    case 2:
        self->f60 = v;
        break;
    }
    VEntry *e = &self->vtbl[33];
    e->fn((char *)self + e->delta, self->f20, v);
}
