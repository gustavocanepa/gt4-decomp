typedef int s32;

struct Obj {
    char pad0[0x44];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
};

extern "C" s32 func_00575610(Obj *arg0) {
    return arg0->unk4C - arg0->unk44;
}
