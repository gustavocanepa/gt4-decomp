typedef int s32;

struct Ctx { char pad[0xF30]; s32 fF30; };
struct Obj { char pad[0x20]; s32 f20; char pad24[0x5C]; Ctx *f80; };
extern "C" void CourseData__render_course(Obj *, s32, s32, s32);
extern "C" void CourseData__render_course_2(Obj *, s32, s32);

extern "C" void func_00397048(Obj *o, s32 arg) {
    if (o->f20)
        return CourseData__render_course(o, o->f20, arg, o->f80->fF30);
    CourseData__render_course_2(o, 0, o->f80->fF30);
}
