typedef int s32;

struct Obj {
    char pad0[0x14];
    s32 unk14;
};

extern s32 D_006456D4;

extern "C" void func_001FA3D0(struct Obj *arg0) {
    if (arg0->unk14 != 0) {
        D_006456D4 = 1;
        arg0->unk14 = 0;
    }
}
