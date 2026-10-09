typedef int s32;
typedef float f32;

struct Sub005CC1A8 {
    char pad0[0x88];
    s32 unk88;
};

struct S005CC1A8 {
    char pad0[0x10];
    Sub005CC1A8 *unk10;
};

extern "C" f32 func_005CC1A8(struct S005CC1A8 *arg0) {
    return (f32)arg0->unk10->unk88 * 0.0078125f;
}
