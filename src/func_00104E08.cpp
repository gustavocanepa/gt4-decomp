typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
    char pad2[0x30 - 0x8 - 4];
    s32 unk30;
};

extern "C" s32 func_00104E08(struct Obj *arg0) {
    if (arg0->unk8 != 0) {
        arg0->unk30 = 1;
    }
    return (arg0->unk30 != 0) ? 0 : -1;
}
