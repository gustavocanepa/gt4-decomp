typedef int s32;

struct Obj {
    char pad[0x364];
    s32 unk364;
};

extern "C" s32 D_006187A8;

extern "C" s32 func_00127BA0(s32 arg0, s32 arg1) {
    return ((Obj *)(D_006187A8 + arg1 * 4))->unk364;
}
