typedef float f32;

struct S {
    f32 v[16];
};

struct Mtx {
    f32 m[16];
};

extern "C" void func_00486600(S *s, f32 *p1, f32 *p2, f32 *p3, f32 *p4, f32 *p5, f32 *p6, f32 *p7, f32 *p8, f32 *p9, f32 *p10, f32 *p11, f32 *p12, f32 *p13, f32 *p14, f32 *p15, f32 m0, f32 m1, f32 m2, f32 m3, f32 m4, f32 m5, f32 m6, f32 m7, f32 m8, f32 m9, f32 m10, f32 m11, f32 m12, f32 m13, f32 m14, f32 m15);

extern "C" void func_00216660(S *s, Mtx *m) {
    func_00486600(s, &s->v[1], &s->v[2], &s->v[3], &s->v[4], &s->v[5], &s->v[6], &s->v[7], &s->v[8], &s->v[9], &s->v[10], &s->v[11], &s->v[12], &s->v[13], &s->v[14], &s->v[15], m->m[0], m->m[1], m->m[2], m->m[3], m->m[4], m->m[5], m->m[6], m->m[7], m->m[8], m->m[9], m->m[10], m->m[11], m->m[12], m->m[13], m->m[14], m->m[15]);
}
