typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_001FEFA8(Guard *);
extern "C" void func_001FEF50(Guard *, s32);

extern "C" void func_001FF1C0(void) {
    Guard g;
    func_001FEFA8(&g);
    {
        VObj *o = g.p;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x190);
        e->fn((char *)o + e->delta);
    }
    func_001FEF50(&g, 2);
}
