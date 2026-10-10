typedef float f32;

struct V4 { f32 x, y, z, w; };
struct Self { f32 m0, m4, m8, mC; };
extern "C" void func_00486430(Self *, f32 *, f32 *, f32 *, f32, f32, f32, f32);

extern "C" void func_00489690(Self *self, V4 *v) {
    func_00486430(self, &self->m4, &self->m8, &self->mC, v->x, v->y, v->z, v->w);
}
