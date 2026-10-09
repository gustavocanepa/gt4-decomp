typedef int s32;
typedef float f32;

struct Elem {
    f32 x;
    f32 y;
    f32 z;
};

struct Obj {
    Elem rows[1][4];
};

extern "C" void func_003CA668(Obj *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2) {
    Elem *p = &arg0->rows[arg1][arg2];
    p->x = fparg0;
    p->y = fparg1;
    p->z = fparg2;
}
