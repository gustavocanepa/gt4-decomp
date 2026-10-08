typedef int s32;
typedef float f32;

struct Obj00370D70 {
    char pad0[0x4C];
    s32 unk4C;
};

extern "C" f32 func_00370D70(struct Obj00370D70 *arg0) {
    return (f32)arg0->unk4C / 100.0f;
}
