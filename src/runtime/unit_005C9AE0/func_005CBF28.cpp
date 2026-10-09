typedef int s32;
typedef float f32;

struct Sub005CBF28 {
    char pad0[0x60];
    s32 unk60;
};

struct S005CBF28 {
    char pad0[0x10];
    Sub005CBF28 *unk10;
};

extern "C" f32 func_005CBF28(struct S005CBF28 *arg0) {
    return (f32)arg0->unk10->unk60 * 0.0078125f;
}
