typedef int s32;

struct Obj004FFBB8 {
    char pad0[0x150];
    s32 unk150;
    char pad1[0x3F40 - 0x150 - 4];
    s32 unk3F40;
};

extern "C" s32 func_004FFBB8(struct Obj004FFBB8 *arg0) {
    if (arg0->unk150 != 0) {
        return 1;
    }
    arg0->unk3F40 = 0;
    arg0->unk150 = 1;
    return 1;
}
