typedef int s32;
typedef float f32;

struct Vec3_003D7698 {
    f32 x, y, z;
};

struct Entry_003D7698 {
    Vec3_003D7698 v;
    s32 m0C;
    s32 m10;
};

struct Table_003D7698 {
    char pad0[0x10];
    Entry_003D7698 e[4];
};

/* The index is reduced modulo 4 twice in the original (in place, the parameter reused). */

Vec3_003D7698 func_003D7698(Table_003D7698 *t, s32 i) {
    i %= 4;
    i %= 4;
    return t->e[i].v;
}
