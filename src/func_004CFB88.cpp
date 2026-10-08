typedef long s64;

struct Obj {
    char pad0[8];
    s64 unk8;
    char pad1[0x18 - 0x10];
    s64 unk18;
};

extern Obj D_00645350;

extern "C" Obj *func_004CFB88(void) {
    D_00645350.unk8 = 1;
    D_00645350.unk18 = 1;
    return &D_00645350;
}
