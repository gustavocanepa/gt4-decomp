typedef int s32;

struct Obj {
    char pad[0x4];
    s32 unk4;
};

extern "C" s32 func_00435E08(Obj *arg0) {
    return *(s32 *)(0x622DA8 + (arg0->unk4 * 4));
}
