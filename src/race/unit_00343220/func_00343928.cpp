typedef float f32;
typedef unsigned char u8;

struct Obj { char pad[0x14]; u8 f14; };
extern char D_00620320[];
extern "C" f32 func_003507D0(const char *);
extern "C" void func_00343698(Obj *, f32);

extern "C" void func_00343928(Obj *o) {
    if (!o->f14)
        return func_00343698(o, func_003507D0(D_00620320));
}
