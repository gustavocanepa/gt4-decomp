typedef int s32;
typedef unsigned short u16;

typedef struct Self { char pad[0x28]; u16 m28; char pad2[0x2A]; void *m54; } Self;
s32 func_00604620(void *, void *, u16);

s32 func_004549F0(Self *self, void *a) {
    if (self->m54 == 0) return 0;
    return func_00604620(a, self->m54, self->m28);
}
