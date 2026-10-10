typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_0022AD20(Guard *);
extern "C" void func_0022ACC8(Guard *, s32);

extern "C" void MRenderContext__releaseScreen(void) {
    Guard g;
    func_0022AD20(&g);
    {
        VObj *o = g.p;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x230);
        e->fn((char *)o + e->delta);
    }
    func_0022ACC8(&g, 2);
}
