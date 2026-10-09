typedef int s32;
typedef float f32;

struct Obj001C5F60 {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
};

extern "C" f32 func_001C5F60(struct Obj001C5F60 *arg0) {
    return (f32)(arg0->unk2C + (arg0->unk30 * 2));
}
