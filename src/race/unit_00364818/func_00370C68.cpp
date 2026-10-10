/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Pair_00370C68 {
    f32 f;
    s32 i;
};

struct Obj_00370C68 {
    char pad0[0x80];
    s32 m80;
    char pad84[0xD8 - 0x84];
    char mD8[0xC];
    Pair_00370C68 mE4;
    char mEC[0xC];
    Pair_00370C68 mF8;
};

extern "C" void func_005F5040(void *dst, void *src);
extern "C" void func_00370548(Obj_00370C68 *obj, void *v, s32 n);

extern "C" void func_00370C68(Obj_00370C68 *arg0) {
    func_005F5040(arg0->mEC, arg0->mD8);
    arg0->mE4.f = arg0->mF8.f;
    arg0->mE4.i = arg0->mF8.i;
    func_00370548(arg0, arg0->mD8, arg0->m80);
}
