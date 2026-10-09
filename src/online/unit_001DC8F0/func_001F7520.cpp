typedef int s32;

struct Obj {
    char pad[0x1B8];
    s32 unk1B8;
};

extern s32 D_00646544;

extern "C" s32 func_001F7520(Obj *arg0) {
    s32 temp_v0 = D_00646544;
    if (temp_v0 != arg0->unk1B8) {
        arg0->unk1B8 = temp_v0;
        return 1;
    }
    return 0;
}
