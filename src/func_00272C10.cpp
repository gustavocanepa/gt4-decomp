typedef int s32;
typedef float f32;

struct Obj { char pad[0x10]; void *f10; s32 f14; char pad18[4]; s32 f1C; };
extern "C" void func_00475488(void *, f32);

extern "C" void func_00272C10(Obj *o) {
    if (o->f1C && o->f10 && o->f14)
        func_00475488(o->f10, 1.0f / 60.0f);
}
