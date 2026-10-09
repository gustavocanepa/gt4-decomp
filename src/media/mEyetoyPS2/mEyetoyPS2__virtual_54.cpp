typedef int s32;

struct Inner001BF120 {
    char pad[0x280];
    s32 unk280;
};

struct Obj001BF120 {
    char pad[0x14];
    struct Inner001BF120 *unk14;
};

extern "C" s32 mEyetoyPS2__virtual_54(struct Obj001BF120 *arg0) {
    struct Inner001BF120 *temp_v0 = arg0->unk14;

    if (temp_v0 != 0) {
        return temp_v0->unk280 ^ 1;
    }
    return 0;
}
