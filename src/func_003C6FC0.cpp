typedef int s32;
typedef float f32;

struct Obj { char pad[0x1E638]; s32 a; s32 b; s32 c; s32 d; f32 f; s32 e; };

extern "C" void func_003C6FC0(Obj *o, s32 a, s32 b, s32 c, s32 d, f32 f, s32 e) {
    o->a = a;
    o->b = b;
    o->c = c;
    o->d = d;
    o->f = f;
    o->e = e;
}
