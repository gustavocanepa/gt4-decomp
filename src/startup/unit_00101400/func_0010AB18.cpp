typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct Self { char pad[0x60]; s32 m60; VEntry *vtbl; };
extern "C" void func_00101100(Self *);

extern "C" void func_0010AB18(Self *self) {
    func_00101100(self);
    if (self->m60 != 0) {
        VEntry *e = (VEntry *)((char *)self->vtbl + 0x48);
        e->fn((char *)self + e->delta);
    }
}
