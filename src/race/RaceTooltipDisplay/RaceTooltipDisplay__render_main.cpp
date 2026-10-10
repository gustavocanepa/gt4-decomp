typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x14];
    VEntry *vtbl;
};

extern "C" void func_001056A0(void *p);

extern "C" void RaceTooltipDisplay__render_main(Obj *self, void *p) {
    func_001056A0(p);
    VEntry *e = self->vtbl + 5;
    e->fn((char *)self + e->delta);
}
