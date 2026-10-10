typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec4 {
    u128 v;
};

struct Mat3 {
    u128 r0, r1, r2;
    void set(const Mat3 *o) { r0 = o->r0; r1 = o->r1; r2 = o->r2; }
};

struct Obj {
    char pad0[0xB0];
    Vec4 pos;
    char padC0[0x30];
    Mat3 rot;
};

extern char D_00622B50[];
extern "C" void func_004887D8(Vec4 *out, void *ref, Vec4 *v);
extern "C" void func_00421C58(Mat3 *out, Vec4 *dir);

extern "C" void func_00415240(Obj *self, Vec4 *v)
{
    self->pos.v = v->v;
    Mat3 *rot = &self->rot;
    Vec4 dir;
    Mat3 m;
    func_004887D8(&dir, D_00622B50, v);
    func_00421C58(&m, &dir);
    rot->set(&m);
}
