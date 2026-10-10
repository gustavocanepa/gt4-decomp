typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0xE2F4];
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    s32 dirty;
};

extern "C" void func_0033DD88(Obj *self, f32 r, f32 g, f32 b, f32 a) {
    self->dirty = 1;
    self->g = g;
    self->b = b;
    self->a = a;
    self->r = r;
}
