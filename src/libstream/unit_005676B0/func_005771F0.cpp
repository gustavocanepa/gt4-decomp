struct Pair {
    int a;
    int b;
};

struct Obj {
    Pair p0;
    Pair p1;
    Pair p2;
    int f18;
    int f1C;
    int f20;
    int f24;
};

extern "C" Pair D_00655880;

extern "C" void func_005771F0(Obj *o, const Pair *p) {
    o->p0 = *p;
    o->p1 = D_00655880;
    o->p2 = D_00655880;
    o->f18 = 0;
    o->f1C = 0;
    o->f20 = 0;
    o->f24 = 0;
}
