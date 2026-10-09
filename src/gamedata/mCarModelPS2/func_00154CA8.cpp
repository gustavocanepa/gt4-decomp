typedef int s32;

struct Obj00154CA8 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    char pad0xC[4];
    s32 unk10;
};

extern "C" void func_00154CA8(struct Obj00154CA8 *arg0, s32 arg1) {
    if ((arg1 == 0) || (arg0->unk10 != 0)) {
        arg0->unk8 = 1;
        arg0->unk4 = 1;
    }
}
