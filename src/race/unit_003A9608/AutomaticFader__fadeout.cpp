typedef int s32;
typedef float f32;

struct Self { char pad[0x10]; f32 rate; char pad2[4]; s32 mode; };
extern f32 D_006A162C;

extern "C" void AutomaticFader__fadeout(Self *self, f32 t) {
    if (t <= 0.0f) self->rate = D_006A162C;
    else self->rate = 0x1.000000p+0f / t;
    self->mode = 2;
}
