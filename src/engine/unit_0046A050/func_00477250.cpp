typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);

extern "C" void func_00477250(Val *self, s32 v) {
    s32 type = 11;
    func_004768C0(self);
    self->type = type;
    self->v = v;
}
