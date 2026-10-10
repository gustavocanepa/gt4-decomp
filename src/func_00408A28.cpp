/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Vec3 {
    f32 x, y, z;
    void set(f32 v) {
        x = v;
        y = v;
        z = v;
    }
};

struct Obj {
    int a;
    int b;
    int c;
    f32 t;
    Vec3 p;
    Vec3 q;
    Vec3 r;
    f32 u;
    int d;
};

extern "C" void func_00408A28(Obj *o) {
    o->t = 0.0f;
    f32 z = o->t;
    o->a = 0;
    o->b = 0;
    o->c = 0;
    o->p.set(z);
    o->q.set(z);
    o->r.set(z);
    o->u = z;
    o->d = 0;
}
