typedef int s32;
typedef float f32;

struct Val { s32 type; f32 v; };
extern "C" void func_004768C0(Val *);

extern "C" void func_00476B78(Val *self, f32 v) {
    s32 type = 6;
    func_004768C0(self);
    self->type = type;
    self->v = v;
}
