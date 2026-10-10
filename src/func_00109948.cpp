typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Obj {
    char pad0[0x5C];
    int pending;
    int pad60;
    VEntry *vtbl;
};

extern "C" void func_00576788(Obj *self);
extern "C" void func_005767C0(Obj *self);
extern "C" void func_005768D8(Obj *self);

extern "C" void func_00109948(Obj *self) {
    func_00576788(self);
    if (self->pending) {
        self->pending = 0;
        VEntry *e = &self->vtbl[11];
        e->fn((char *)self + e->delta);
        func_005768D8(self);
    }
    func_005767C0(self);
}
