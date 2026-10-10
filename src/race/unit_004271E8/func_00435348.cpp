typedef int s32;

struct Entry { s32 flags; s32 pad[7]; };
struct Self { char pad[0x10]; Entry e[1000]; };

extern "C" s32 func_00435348(Self *self) {
    s32 i;
    for (i = 0; i < 1000; i++) {
        if ((self->e[i].flags & 1) == 0) return i;
    }
    return -1;
}
