struct Mat33 {
    float m[9];
};

struct Obj {
    float m0, m4, m8, mC, m10, m14, m18, m1C, m20;
};

extern "C" void func_00486490(Obj *o, float *a, float *b, float *c, float *d, float *e, float *f, float *g, float *h,
                              float m0, float m1, float m2, float m3, float m4, float m5, float m6,
                              float m7, float m8);

extern "C" void func_00489B38(Obj *o, Mat33 *m)
{
    func_00486490(o, &o->m4, &o->m8, &o->mC, &o->m10, &o->m14, &o->m18, &o->m1C, &o->m20,
                  m->m[0], m->m[1], m->m[2], m->m[3], m->m[4], m->m[5], m->m[6], m->m[7], m->m[8]);
}
