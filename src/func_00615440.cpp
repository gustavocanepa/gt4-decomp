typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0xC - 4];
    s32 unkC;
    char pad2[0x24 - 0xC - 4];
    s32 unk24;
};

extern "C" s32 func_00615440(Obj *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unk24;
    }
    return arg0->unkC;
}
