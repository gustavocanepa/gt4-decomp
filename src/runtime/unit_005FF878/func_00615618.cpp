typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0x4];
    s32 unk8;
    char pad2[0x20];
    s32 unk2C;
};

extern "C" s32 func_00615618(Obj *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unk8;
    }
    return arg0->unk2C;
}
