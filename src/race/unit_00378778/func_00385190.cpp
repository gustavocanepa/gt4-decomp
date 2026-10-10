typedef int s32;
typedef float f32;

struct Obj {
    f32 f0;
    f32 f4;
    s32 i8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
};

extern "C" void func_00385190(Obj *o, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    if (o->f0 < 0x1.0624dcp-10f)
        o->f0 = 0x1.0624dcp-10f;
    o->f0 = a;
    o->f4 = a;
    o->fC = b;
    o->f10 = c;
    o->f14 = d;
    o->f18 = e;
    o->i8 = 0;
    o->f1C = f;
}
