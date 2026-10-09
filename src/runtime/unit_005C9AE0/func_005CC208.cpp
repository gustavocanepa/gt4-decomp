typedef int s32;
typedef float f32;

struct Sub005CC208 {
    char pad0[0x8C];
    s32 unk8C;
};

struct S005CC208 {
    char pad0[0x10];
    Sub005CC208 *unk10;
};

extern "C" f32 func_005CC208(struct S005CC208 *arg0) {
    return (f32)arg0->unk10->unk8C * 0.0078125f;
}
