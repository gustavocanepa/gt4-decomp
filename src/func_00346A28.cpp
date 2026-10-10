typedef int s32;

struct Obj {
    char pad[0x4];
    void *unk4;
    char pad8[0x58];
    s32 unk60;
};

extern "C" s32 func_00346A28(Obj *arg0) {
    if (arg0->unk4 == 0) {
        return 0;
    }
    return arg0->unk60;
}
