typedef int s32;

struct Self { char pad[0x18]; s32 m18; };
extern "C" void func_00215298(s32);

extern "C" void func_0024D298(Self *self) {
    while (self->m18 == 1 || self->m18 == 2) {
        func_00215298(1);
    }
}
