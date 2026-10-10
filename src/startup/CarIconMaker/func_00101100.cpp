typedef short s16;
typedef float f32;

struct VEntry { s16 delta; s16 index; void (*fn)(void *, f32); };
struct VObj { char pad[0x64]; VEntry *vtbl; };

extern "C" void func_00101100(VObj *self) {
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x70);
    e->fn((char *)self + e->delta, 0x1.111110p-6f);
}
