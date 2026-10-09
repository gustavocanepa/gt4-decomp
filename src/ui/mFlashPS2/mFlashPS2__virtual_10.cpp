typedef int s32;

struct Obj00272B38 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    char pad1[0x1C - 0x18];
    s32 unk1C;
};

extern "C" s32 mFlashPS2__virtual_10(struct Obj00272B38 *arg0) {
    s32 var_v1;

    if (arg0->unk1C != 0) {
        var_v1 = 0;
        if (arg0->unkC != 0) {
            if (arg0->unk10 != 0) {
                var_v1 = arg0->unk14 != 0;
            }
        }
        return var_v1;
    } else {
        return arg0->unkC != 0;
    }
}
