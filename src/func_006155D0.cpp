typedef int s32;

struct Obj00615410 {
    s32 unk0;
    char pad0[0x8 - 4];
    s32 unk8;
    char pad1[0x2C - 0x8 - 4];
    s32 unk2C;
};

extern "C" s32 func_006155D0(struct Obj00615410 *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unk2C;
    }
    return arg0->unk8;
}
