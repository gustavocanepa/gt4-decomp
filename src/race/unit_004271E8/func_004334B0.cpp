typedef int s32;
typedef float f32;

struct Ent { char pad[8]; f32 v; char pad2[0x24]; };
struct Self { Ent e[10]; };

extern "C" s32 func_004334B0(Self *self) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 10; i++) {
        if (self->e[i].v != 0.0f) n++;
    }
    return n;
}
