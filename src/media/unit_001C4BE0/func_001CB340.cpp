typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad0[4];
    s32 unk4;
    u8 *unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" s32 func_001CB340(struct Obj *arg0, s32 arg1, s32 arg2) {
    s32 idx = (arg0->unk10 - arg2 - 1) * arg0->unkC + arg1;
    return arg0->unk4 + (arg0->unk8[idx] << 2);
}
