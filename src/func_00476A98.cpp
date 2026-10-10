typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);
extern "C" s32 func_00476650(const char *);

extern "C" void func_00476A98(Val *self, const char *s) {
    s32 type = 3;
    func_004768C0(self);
    self->type = type;
    self->v = func_00476650(s);
}
