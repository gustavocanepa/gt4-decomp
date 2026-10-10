typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);

extern "C" void func_00477208(Val *self, s32 v) {
    s32 type = 10;
    func_004768C0(self);
    self->type = type;
    self->v = v;
}
