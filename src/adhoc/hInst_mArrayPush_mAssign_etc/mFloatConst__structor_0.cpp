typedef int s32;
typedef float f32;

struct Obj {
    s32 a;
    void *vtbl;
    f32 f;
};

extern char mFloatConst__vtable[];
extern "C" Obj *RefCounter__structor_0(Obj *);

extern "C" Obj *mFloatConst__structor_0(Obj *self, f32 f) {
    Obj *r = RefCounter__structor_0(self);
    self->vtbl = mFloatConst__vtable;
    self->f = f;
    return r;
}
