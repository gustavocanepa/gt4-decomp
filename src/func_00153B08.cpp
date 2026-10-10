typedef float f32;

struct Vec3 {
    f32 x, y, z;
    void set(f32 a, f32 b, f32 c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Obj {
    char pad[0x14];
    f32 s14, s18, s1C, s20, s24, s28;
    f32 d2C, d30, d34, d38;
    Vec3 v;
    f32 d48;
};

extern "C" void func_00153B08(Obj *o) {
    Vec3 *v = &o->v;
    o->d2C = o->s14;
    o->d30 = o->s18;
    o->d34 = o->s1C;
    o->d38 = o->s20;
    v->set(0.0f, 0.0f, o->s24);
    o->d48 = o->s28;
}
