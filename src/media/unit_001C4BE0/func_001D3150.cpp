struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};
struct VObj {
    VEntry *vtbl;
};
static inline int vcall7(VObj *o)
{
    VEntry *e = &o->vtbl[7];
    return e->fn((char *)o + e->delta);
}
struct Player {
    char pad[0x30];
    VObj *stream;
    char pad2[0x674 - 0x34];
    int count;
    int loop;
    char pad3[0x69C - 0x67C];
    int frame;
    int mode;
    char pad4[0x6CC - 0x6A4];
    int dirty;
};
extern "C" void func_001D31D0(Player *p, int a, int b);

extern "C" void func_001D3150(Player *p)
{
    if (p->loop == 0 || p->mode != 8) {
        if (!vcall7(p->stream))
            func_001D31D0(p, 0, p->count - 1);
    }
    p->dirty = 1;
    p->frame++;
}
