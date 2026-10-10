typedef int s32;
typedef float f32;

struct mListBox_002B4728 {
    char pad0[0x120];
    f32 unk120;
    s32 unk124;
};

extern "C" s32 mListBox__canDecrement(mListBox_002B4728 *arg0) {
    s32 var_v0;

    if (arg0->unk124 == 0) {
        return 0;
    }
    var_v0 = 1;
    if (!(arg0->unk120 < 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
