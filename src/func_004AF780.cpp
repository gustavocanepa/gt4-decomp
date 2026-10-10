typedef int s32;

struct Obj;

struct Callback {
    void (*fn)(void *, Obj *);
    void *arg;
};

struct Target {
    char pad[0x84];
    s32 id;
};

struct Obj {
    s32 id;
    Target *target;
    char pad8[0x10];
    Callback cb;
};

extern "C" void func_004AF780(Obj *o, Target *t) {
    o->target = t;
    Callback *cb = &o->cb;
    if (cb->fn != 0)
        cb->fn(cb->arg, o);
    t->id = o->id;
}
