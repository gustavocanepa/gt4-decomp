typedef int s32;
typedef float f32;

struct Self { f32 m0, m4; s32 m8; f32 mC, m10, m14, m18, m1C, m20; };

extern "C" void func_00385058(Self *s, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    s->m0 = a;
    s->m4 = a;
    s->m8 = 0;
    s->mC = e / 0x1.e00000p+5f;
    s->m10 = b;
    s->m14 = c;
    s->m18 = d;
    s->m1C = f;
    s->m20 = g;
}
