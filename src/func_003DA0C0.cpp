typedef int s32;

struct T2 {
    char pad0[0x8];
    s32 *unk8;
};

struct T1 {
    char pad0[0x60];
    T2 *unk60;
};

struct T0 {
    char pad0[0xC];
    T1 *unkC;
    char pad1[0x60 - 0xC - 4];
    s32 unk60;
};

extern "C" s32 func_003DA0C0(T0 *arg0) {
    T1 *v0 = arg0->unkC;
    s32 idx = arg0->unk60;
    T2 *t = v0->unk60;
    s32 *base = t->unk8;
    return base[idx];
}
