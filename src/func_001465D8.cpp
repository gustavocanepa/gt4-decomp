typedef int s32;
typedef float f32;

struct Obj001465D8 {
    char pad0[0x178];
    s32 unk178;
};

extern "C" f32 func_001465D8(struct Obj001465D8 *arg0) {
    return (f32)arg0->unk178 / 100.0f;
}
