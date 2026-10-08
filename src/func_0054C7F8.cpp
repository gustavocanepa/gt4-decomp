typedef int s32;

struct S0086DD84 {
    s32 unk0;
    char pad4[8];
};

extern "C" struct S0086DD84 D_0086DD84[];

extern "C" s32 func_0054C7F8(s32 arg0) {
    return D_0086DD84[arg0].unk0;
}
