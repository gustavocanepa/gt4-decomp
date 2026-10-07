typedef float f32;

struct S00395400;

extern "C" f32 func_00395528(S00395400 *arg0);

struct Obj {
    char pad0[0xCBD8];
    S00395400 *ptr;
};

extern "C" f32 func_0034C318(Obj *arg0) {
    return func_00395528(arg0->ptr);
}
