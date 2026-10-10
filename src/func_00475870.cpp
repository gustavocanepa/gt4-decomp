typedef int s32;
typedef float f32;

struct Vec2 {
    f32 x;
    f32 y;
};

struct Param {
    char pad0[0x90];
    Vec2 pos;
};

struct Obj {
    char pad0[0x28];
    Param *cur;
};

extern "C" void func_004765B0(Obj *self, f32 x, f32 y);
extern "C" void func_004756F8(Obj *self);

extern "C" void func_00475870(Obj *self, Param *p) {
    Vec2 *v = &p->pos;
    if (self->cur != p) {
        self->cur = p;
        func_004765B0(self, v->x, v->y);
        func_004756F8(self);
    }
}
