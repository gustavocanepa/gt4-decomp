typedef int s32;
typedef float f32;

struct Obj_00370D08 {
    char pad0[0x48];
    s32 m48;
    char pad4C[0x60 - 0x4C];
    char m60[0xC];
    f32 m6C;
    char pad70[0x10];
    s32 m80;
    char pad84[0xCC - 0x84];
    f32 mCC;
};

extern "C" f32 func_0036F4E0(s32 *p);
extern "C" void func_00370EF8(Obj_00370D08 *o, f32 *a, f32 *b, void *c, s32 d, f32 e);

extern "C" void func_00370D08(Obj_00370D08 *o, f32 t) {
    f32 a;
    f32 v;
    s32 *p = &o->m48;
    *p = (s32)(t * 10.0f);
    v = func_0036F4E0(p);
    func_00370EF8(o, &a, &v, o->m60, o->m80, o->m6C);
    o->mCC = v;
}
