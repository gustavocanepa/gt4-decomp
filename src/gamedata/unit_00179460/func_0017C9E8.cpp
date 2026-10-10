typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32, s32, s32, s32); };
struct VObj { char pad[0x4C]; VEntry *vtbl; };
struct Self { char pad[0x18]; VObj *m18; s32 m1C; char pad2[8]; s32 m28; };

extern "C" void func_0017C9E8(Self *self, s32 a) {
    VObj *o = self->m18;
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x20);
    e->fn((char *)o + e->delta, self->m1C, a, self->m28, 0);
}
