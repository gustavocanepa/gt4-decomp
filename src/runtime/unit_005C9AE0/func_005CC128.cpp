typedef int s32;
typedef float f32;

struct Sub005CC128 {
    char pad0[0x80];
    s32 unk80;
};

struct S005CC128 {
    char pad0[0x10];
    Sub005CC128 *unk10;
};

extern "C" f32 func_005CC128(struct S005CC128 *arg0) {
    return (f32)arg0->unk10->unk80 * 0.0078125f;
}
