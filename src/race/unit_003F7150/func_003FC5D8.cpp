typedef int s32;
typedef float f32;

struct Obj003FC5D8 {
    char pad0[0x30];
    f32 unk30;
    char pad1[0x5C - 0x30 - 4];
    f32 unk5C;
    char pad2[0x6C - 0x5C - 4];
    s32 unk6C;
};

extern "C" f32 func_003FC5D8(Obj003FC5D8 *arg0) {
    if (arg0->unk6C < 2) {
        return arg0->unk30;
    }
    return arg0->unk5C;
}
