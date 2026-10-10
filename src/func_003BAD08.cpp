typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x10];
    s32 handle;
};

extern "C" void func_00393548(s32 handle, s32 flags, f32 a, f32 b);

extern "C" void func_003BAD08(Obj *self) {
    if (self->handle >= 0) {
        func_00393548(self->handle, 0x40, 1.0f, 1.0f);
        self->handle = -1;
    }
}
