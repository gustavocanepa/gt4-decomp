typedef float f32;
typedef short s16;

struct Obj {
    char pad[0x1C];
    f32 unk1C;
    char pad2[0x20 - 0x1C - 4];
    s16 unk20;
};

extern "C" f32 func_004743D0(struct Obj *arg0) {
    return (f32)arg0->unk20 / arg0->unk1C;
}
