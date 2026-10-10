typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct Elem003E6DE8 {
    s32 unk0;
    f32 *unk4;
};

struct Obj003E6DE8 {
    char pad0[0x8];
    u16 unk8;
    char pad1[0x14 - 0x8 - 2];
    struct Elem003E6DE8 *unk14;
};

extern "C" f32 GT4Course__RunwayData__getCheckPoint(struct Obj003E6DE8 *arg0, s32 arg1, s32 arg2) {
    if (arg2 < arg0->unk8) {
        return arg0->unk14[arg2].unk4[arg1];
    }
    return 0.0f;
}
