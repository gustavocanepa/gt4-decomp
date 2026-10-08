typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x24];
    f32 unk24;
    char pad1[0x3C - 0x24 - 4];
    s32 unk3C;
};

extern "C" void func_0024D1D0(struct Obj *arg0);

extern "C" void func_0028A4F0(struct Obj *arg0) {
    func_0024D1D0(arg0);
    arg0->unk3C = 0;
    arg0->unk24 = 1.0f;
}
