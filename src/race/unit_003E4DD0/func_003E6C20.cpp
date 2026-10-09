typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct Elem003E6C20 {
    s32 unk0;
    f32 *unk4;
};

struct Obj003E6C20 {
    char pad0[0x38];
    u16 unk38;
    char pad1[0x58 - 0x38 - 2];
    struct Elem003E6C20 *unk58;
};

extern "C" f32 func_003E6C20(struct Obj003E6C20 *arg0, s32 arg1, s32 arg2) {
    if (arg2 < arg0->unk38) {
        return arg0->unk58[arg2].unk4[arg1];
    }
    return 0.0f;
}
