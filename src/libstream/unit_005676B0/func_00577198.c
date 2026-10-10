/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

typedef struct {
    s32 a;
    s32 b;
} Pair_00577198;

typedef struct {
    Pair_00577198 m0;
    Pair_00577198 m8;
    Pair_00577198 m10;
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
} Obj_00577198;

extern Pair_00577198 D_00655878;
extern Pair_00577198 D_00655880;

void func_00577198(Obj_00577198 *o) {
    o->m0 = D_00655878;
    o->m8 = D_00655880;
    o->m10 = D_00655880;
    o->m18 = 0;
    o->m1C = 0;
    o->m20 = 0;
    o->m24 = 1;
}
