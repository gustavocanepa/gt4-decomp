typedef int s32;

struct Obj {
    char pad0[0x44];
    s32 unk44;
};

extern "C" s32 func_004EE698(Obj *arg0, s32 arg1) {
    return arg0->unk44 + (arg1 * 0x70) + 0x40;
}
