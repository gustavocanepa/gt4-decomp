typedef float f32;

struct Part { char b[0x20]; };
struct Obj { char pad[4]; Part a; Part b; };
extern "C" void func_003A9640(Part *, f32);
extern "C" void func_003A9780(Part *, f32);

extern "C" void func_003A39B0(Obj *o) {
    f32 dt = 1.0f / 60.0f;
    func_003A9640(&o->a, dt);
    func_003A9780(&o->b, dt);
}
