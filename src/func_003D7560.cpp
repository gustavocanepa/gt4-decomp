typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x4];
    s32 unk4;
};

extern "C" s32 func_00345108(s32 arg0, f32 arg1);

extern "C" s32 func_003D7560(struct Obj *arg0) {
    return func_00345108(arg0->unk4, 0.0f);
}
