typedef int s32;

struct Obj {
    char pad0[0x4C];
    s32 unk4C;
};

extern "C" s32 func_004EE7A0(Obj *arg0, s32 arg1) {
    return arg0->unk4C + (arg1 * 0x1D0) + 0xD0;
}
