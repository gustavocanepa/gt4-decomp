typedef int s32;
typedef float f32;

struct Obj_0021B528 {
    s32 m0;
    f32 m4;
    s32 m8;
    s32 mC;
    s32 m10;
};

extern "C" void func_0021B528(Obj_0021B528 *o, f32 t, f32 d) {
    if (t < o->m4) {
        if (o->mC >= 0) {
            o->m8 = o->mC;
            o->m4 = 0.0f;
            o->mC = -1;
        } else if (o->m10 != 0) {
            o->m4 = o->m4 - (t - d);
        } else {
            o->m4 = t;
            o->m0 = 0;
        }
    }
}
