typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad0[0x4CC];
    f32 unk4CC;
    f32 unk4D0;
};

extern "C" s32 func_00354E68(u8 *arg0) {
    Obj *p = (Obj *)(arg0 + 0x104);
    s32 var_v0 = 0;

    if (p->unk4CC > 0.0f && p->unk4D0 <= 0.0f) {
        var_v0 = 1;
    }
    return var_v0;
}
