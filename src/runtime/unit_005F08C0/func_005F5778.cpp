typedef int s32;
typedef float f32;

struct Obj005F5778 {
    char pad0[0x140];
    s32 unk140;
};

extern "C" f32 func_005F5778(struct Obj005F5778 *arg0) {
    return (f32)arg0->unk140 / 60.0f;
}
