typedef int s32;
typedef float f32;

struct Obj {
    s32 a;
    void *vtbl;
    f32 f;
};

extern char D_00675E90[];
extern "C" Obj *func_00328420(Obj *);

extern "C" Obj *func_0031B748(Obj *self, f32 f) {
    Obj *r = func_00328420(self);
    self->vtbl = D_00675E90;
    self->f = f;
    return r;
}
