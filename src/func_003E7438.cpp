typedef int s32;

struct Result { s32 pad[4]; s32 p; s32 pad14[3]; };
struct Obj { s32 f0; s32 f4; };
extern "C" void func_004AE268(Result *, s32, s32, s32, s32);
extern "C" void func_003E7410(Obj *);

extern "C" void func_003E7438(Obj *o, s32 a, s32 b, s32 c) {
    if (o->f4 == 0) {
        Result r;
        o->f0 = b;
        func_004AE268(&r, a, b, c, 1);
        o->f4 = r.p;
        func_003E7410(o);
    }
}
