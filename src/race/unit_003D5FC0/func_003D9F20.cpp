typedef int s32;

struct StructD {
    char pad[8];
    s32 *unk8;
};

struct StructC {
    char pad[0x60];
    StructD *unk60;
};

struct StructE {
    char pad[0x14];
    s32 unk14;
};

struct MainObj {
    char pad0[0xC];
    StructC *unkC;
    char pad1[0x28 - 0x10];
    s32 unk28;
    char pad2[0x64 - 0x2C];
    s32 unk64;
    char pad3[0x9C - 0x68];
    s32 unk9C;
    char pad4[0xA4 - 0xA0];
    s32 unkA4;
};

extern "C" void func_003B6FD0(void *arg0);
extern "C" void func_003D8AC0(void *arg0, s32 arg1);
extern "C" StructE *func_003D8CB8(void *arg0, s32 arg1);
extern "C" StructE *func_003D8D08(void *arg0);

extern "C" void func_003D9F20(MainObj *arg0) {
    StructE *v0;

    func_003B6FD0(arg0->unkC->unk60);
    v0 = func_003D8CB8(arg0, arg0->unkC->unk60->unk8[arg0->unk64]);
    if (v0 == 0) {
        v0 = func_003D8D08(arg0);
    }
    func_003D8AC0(arg0, v0->unk14);
    if (arg0->unk28 == 1) {
        arg0->unk9C = 2;
    }
    arg0->unkA4 = (arg0->unkA4 & ~0xFF) | 1;
}
