typedef int s32;
typedef float f32;

struct Spec_003D75F0 {
    char pad0[0x38];
    f32 m38;
    char pad3C[0x4C - 0x3C];
    f32 m4C;
};

struct C_003D75F0 {
    char pad0[0x80];
    Spec_003D75F0 *m80;
};

struct B_003D75F0 {
    char pad0[4];
    C_003D75F0 *m4;
};

struct A_003D75F0 {
    char pad0[8];
    B_003D75F0 *m8;
};

struct Obj_003D75F0 {
    char pad0[4];
    A_003D75F0 *m4;
    char pad8[4];
    signed char mC[1];
};

extern "C" f32 func_003F3A28(A_003D75F0 *a, s32 idx, f32 t);

extern "C" f32 func_003D75F0(Obj_003D75F0 *arg0, s32 i) {
    A_003D75F0 *a = arg0->m4;
    Spec_003D75F0 *s = a->m8->m4->m80;
    return func_003F3A28(a, arg0->mC[i], 0.0f) * s->m4C / s->m38;
}
