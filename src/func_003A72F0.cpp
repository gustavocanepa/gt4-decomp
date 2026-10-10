typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Part { char b[0x20]; };
struct Obj { char pad[0x18]; u8 f18; char pad19[3]; Part p; };
extern "C" void func_003A9640(Part *, f32);
extern "C" void func_003A9738(Part *, s32, s32);

extern "C" void func_003A72F0(Obj *o, f32 dt) {
    func_003A9640(&o->p, dt);
    func_003A9738(&o->p, o->f18 ? -1 : 0, 0);
}
