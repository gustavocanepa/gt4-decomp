typedef int s32;
typedef float f32;

struct Obj {
    s32 unk0;
    f32 t;
};

extern "C" void func_00456850(f32 frac);

extern "C" s32 func_00452F28(Obj *self) {
    f32 f = self->t * 6.0f;
    s32 i = (s32)f;
    func_00456850(f - (f32)i);
    return i;
}
