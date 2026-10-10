typedef int s32;

struct Ctx { char pad[0xF30]; s32 fF30; };
struct Obj { char pad[0x20]; s32 f20; char pad24[0x5C]; Ctx *f80; };
extern "C" void func_00396E10(Obj *, s32, s32, s32);
extern "C" void func_00396F00(Obj *, s32, s32);

extern "C" void func_00397048(Obj *o, s32 arg) {
    if (o->f20)
        return func_00396E10(o, o->f20, arg, o->f80->fF30);
    func_00396F00(o, 0, o->f80->fF30);
}
