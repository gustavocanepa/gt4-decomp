typedef int s32;

struct Obj {
    char pad[0x14C];
    s32 unk14C;
};

extern "C" s32 func_00600040(Obj *arg0, s32 arg1) {
    s32 k = 0x14F4;
    return arg0->unk14C + (arg1 * k);
}
