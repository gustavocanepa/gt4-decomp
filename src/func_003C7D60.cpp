typedef int s32;
typedef float f32;

struct Sub {
    char pad0[0xF84];
    f32 angle;
};

struct Obj {
    char pad0[0x1E648];
    f32 level;
    char pad1E64C[0x34];
    Sub sub;
};

extern "C" void func_003C7D60(Obj *self, s32 on) {
    Sub *p = &self->sub;
    p->angle = (on && self->level < 1.0f) ? 90.0f : 0.0f;
}
