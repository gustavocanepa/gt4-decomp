typedef float f32;

struct G { f32 m0, m4, m8; };
extern G D_0088F2D0;

extern "C" void RaceCarSound__fadeMasterVolume(f32 x, f32 y) {
    G *g = &D_0088F2D0;
    f32 base = g->m0;
    g->m8 = x;
    g->m4 = (x - base) / 0x1.e00000p+5f / y;
}
