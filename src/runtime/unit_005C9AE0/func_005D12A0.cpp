typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, float);
};

struct Target {
    char *vtbl;
};

struct Obj {
    char pad[4];
    Target *target;
    float from;
    float to;
};

extern "C" void func_005D12A0(Obj *o, float t) {
    float a = o->from;
    Target *p = o->target;
    VEntry *e = (VEntry *)(p->vtbl + 0x10);
    e->fn((char *)p + e->delta, a + (o->to - a) * t);
}
