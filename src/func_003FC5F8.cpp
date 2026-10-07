typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x34];
    f32 unk34;
    char pad1[0x60 - 0x34 - 4];
    f32 unk60;
    char pad2[0x6C - 0x60 - 4];
    s32 unk6C;
};

extern "C" f32 func_003FC5F8(Obj *arg0) {
    if (arg0->unk6C < 2) {
        return arg0->unk34;
    }
    return arg0->unk60;
}
