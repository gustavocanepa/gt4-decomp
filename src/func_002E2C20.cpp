typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x24];
    s32 unk24;
    char pad1[0x3C - 0x24 - 4];
    s32 unk3C;
    f32 unk40;
};

extern "C" void func_002E2C20(Obj *arg0) {
    arg0->unk3C = 0;
    arg0->unk40 = 0.1f;
    arg0->unk24 = 0;
}
