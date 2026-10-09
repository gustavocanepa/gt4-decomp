typedef int s32;

struct Obj {
    char pad0[0x724];
    s32 unk724;
    char pad724[0xA10 - 0x724 - 4];
    s32 unkA10;
    char padA10[0xA34 - 0xA10 - 4];
    s32 unkA34;
    char padA34[0xA40 - 0xA34 - 4];
    s32 unkA40;
    char padA40[0xFD0 - 0xA40 - 4];
    s32 unkFD0;
};

extern "C" void func_004FAC30(Obj *arg0) {
    s32 v1 = arg0->unkFD0 + 1;
    s32 v0 = arg0->unkA40 + 1;
    arg0->unkA34 = 0;
    arg0->unkFD0 = v1;
    arg0->unkA40 = v0;
    arg0->unkA10 = v0;
    arg0->unk724 = v0;
}
