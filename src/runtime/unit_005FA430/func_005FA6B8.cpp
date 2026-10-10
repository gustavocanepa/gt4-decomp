typedef short s16;
typedef unsigned char u8;

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct Self { u8 active; char pad[0x13]; VEntry *vtbl; };

extern "C" void func_005FA6B8(Self *self) {
    if (self->active) {
        VEntry *e = (VEntry *)((char *)self->vtbl + 0x28);
        e->fn((char *)self + e->delta);
    }
}
