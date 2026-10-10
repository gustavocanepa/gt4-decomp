typedef float f32;

struct Obj {
    char pad0[0x18];
    f32 sx;
    f32 sy;
    f32 kx;
    f32 ky;
    f32 x;
    f32 y;
};

extern "C" void func_0044DC10(Obj *o, f32 x, f32 y);

extern "C" void func_0044DBC0(Obj *o, f32 x, f32 y) {
    o->x = x;
    o->y = y;
    func_0044DC10(o, x * o->sx * o->kx, y * o->sy * o->ky);
}
