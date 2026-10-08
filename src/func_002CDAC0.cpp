typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    char pad1[0x2C - 0x20 - 4];
    s32 unk2C;
};

extern "C" void func_002CDAC0(struct Obj *arg0) {
    if (arg0->unk2C != 0) {
        arg0->unk20 = arg0->unk1C;
        return;
    }
    arg0->unk20 = arg0->unk18;
}
