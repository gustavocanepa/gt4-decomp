typedef int s32;
typedef float f32;

struct Obj {
    s32 kind;
};

extern "C" s32 func_0026EEF8(Obj *);
extern "C" s32 func_0026F2B8(Obj *, f32);

extern "C" s32 func_0026F060(Obj *self) {
    switch (self->kind) {
    case 0:
        return func_0026F2B8(self, 0.0f);
    case 1:
    case 2:
        return func_0026EEF8(self);
    }
    return 0;
}
