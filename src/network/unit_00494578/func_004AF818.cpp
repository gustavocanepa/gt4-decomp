typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, void *); };
struct VObj { char pad[0xA4]; VEntry *vtbl; };
extern "C" VObj *func_004AFA78(void *);

extern "C" s32 func_004AF818(void *self) {
    VObj *o = func_004AFA78(self);
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x88);
    return e->fn((char *)o + e->delta, self);
}
