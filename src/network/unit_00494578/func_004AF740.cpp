typedef int s32;

struct P8 { s32 a, b; };
struct Self { s32 m0, m4, m8, mC, m10, m14; P8 m18; };

extern "C" void func_004AF740(Self *self) {
    P8 t;
    t.a = 0;
    t.b = 0;
    self->m10 = 1;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m14 = 0;
    self->m0 = 0;
    self->m18 = t;
}
