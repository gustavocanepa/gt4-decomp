/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct V3 { f32 x, y, z; };
struct Self { s32 m0, m4, m8, mC; f32 x, y, z; s32 m1C, m20, m24, m28, m2C, m30; char pad[0x14]; s32 m48; };

extern "C" void func_003E2980(Self *s, V3 *v) {
    s->x = v->x;
    s->y = v->y;
    s->z = v->z;
    s->m1C = 0;
    s->m20 = 0;
    s->m24 = 0;
    s->m28 = 0;
    s->m2C = 0;
    s->m30 = 0;
    s->m4 = 0;
    s->m8 = 0;
    s->mC = 0;
    s->m48 = -1;
}
