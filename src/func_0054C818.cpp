typedef int s32;

struct S0086DD84 {
    s32 unk0;
    char pad4[8];
};

extern "C" struct S0086DD84 D_0086DD88[];

extern "C" s32 func_0054C818(s32 arg0) {
    return D_0086DD88[arg0].unk0;
}
