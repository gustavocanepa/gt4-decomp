typedef float f32;

struct Mtx { f32 m[16]; };

extern "C" void func_00425558(Mtx *o, f32 x, f32 y, f32 z) {
    f32 zero = 0.0f;
    f32 one = 1.0f;
    o->m[12] = x;
    o->m[13] = y;
    o->m[14] = z;
    o->m[0] = one;
    o->m[4] = zero;
    o->m[8] = zero;
    o->m[1] = zero;
    o->m[5] = one;
    o->m[9] = zero;
    o->m[2] = zero;
    o->m[6] = zero;
    o->m[10] = one;
    o->m[3] = zero;
    o->m[7] = zero;
    o->m[11] = zero;
    o->m[15] = one;
}
