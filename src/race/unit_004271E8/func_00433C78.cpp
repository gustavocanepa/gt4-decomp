typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00433C78(Obj *arg0, s32 arg1) {
    return arg0->unk4 + (arg1 * 0x238);
}
