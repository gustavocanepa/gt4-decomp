/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Obj {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    char pad14[0x2C - 0x14];
    int f2C;
    int f30;
    int *f34;
    f32 rate;
    f32 invRate;
    f32 f40;
    int f44;
    int f48;
};

extern "C" void func_0011E400(Obj *o, int a, int *p, f32 rate, f32 b, int c) {
    o->f30 = a;
    o->f40 = b;
    o->f44 = c;
    o->f34 = p;
    o->rate = rate;
    o->invRate = 1.0f / rate;
    *p = 0;
    o->f48 = 1;
    o->f8 = 0;
    o->fC = 0;
    o->f10 = 0;
    o->f2C = 0;
}
