typedef int s32;
typedef float f32;

struct Sub005CC028 {
    char pad0[0x70];
    s32 unk70;
};

struct S005CC028 {
    char pad0[0x10];
    Sub005CC028 *unk10;
};

extern "C" f32 func_005CC028(struct S005CC028 *arg0) {
    return (f32)arg0->unk10->unk70 * 0.0078125f;
}
