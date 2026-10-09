typedef int s32;

struct Obj {
    char pad0[8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_003FFA20(Obj *arg0) {
    return arg0->unk8 + (arg0->unkC * 0x74);
}
