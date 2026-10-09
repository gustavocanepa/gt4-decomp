typedef int s32;

struct Obj {
    char pad[0x454];
    s32 unk454;
};

extern "C" s32 D_006187A8;

extern "C" s32 func_00127DF8(s32 arg0, s32 arg1) {
    return ((Obj *)(D_006187A8 + arg1 * 4))->unk454;
}
