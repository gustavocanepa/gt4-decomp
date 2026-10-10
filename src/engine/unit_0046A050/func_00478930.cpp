typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);

/* type 6 (float) set to a quiet NaN, stored as its bit pattern */
extern "C" void func_00478930(Val *self) {
    func_004768C0(self);
    self->type = 6;
    self->v = 0x7FC00000;
}
