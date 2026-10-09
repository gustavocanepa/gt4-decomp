typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    char pad[0x1C];
    s32 unk24;
};

extern "C" s32 func_006153E8(Obj *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unk24;
    }
    return arg0->unk4;
}
