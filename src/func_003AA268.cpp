typedef int s32;
typedef float f32;

struct Vec3 {
    f32 x, y, z;
    void set(f32 a, f32 b, f32 c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Obj {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    Vec3 scale;
    Vec3 offset;
};

extern "C" void func_003AA268(Obj *self) {
    Vec3 *s = &self->scale;
    Vec3 *o = &self->offset;
    self->unk4 = 3.0f;
    self->unk8 = 0.0f;
    s->set(1.0f, 1.0f, 1.0f);
    o->set(0.0f, 0.0f, 0.0f);
}
