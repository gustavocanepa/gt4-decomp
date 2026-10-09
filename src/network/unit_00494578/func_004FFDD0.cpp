typedef int s32;

struct Obj004FFDD0 {
    char pad0[0x3F20];
    s32 unk3F20;
    s32 unk3F24;
};

extern "C" s32 func_004FFDD0(struct Obj004FFDD0 *arg0) {
    if (arg0->unk3F20 == 0) {
        return 0;
    }
    arg0->unk3F24 = 0;
    return 1;
}
