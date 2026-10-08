typedef int s32;
typedef float f32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00350F30(s32 arg0);

extern "C" f32 func_003D75C8(Obj *arg0) {
    return (f32)func_00350F30(arg0->unk4);
}
