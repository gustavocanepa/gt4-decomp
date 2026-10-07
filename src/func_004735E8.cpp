typedef int s32;

struct Obj {
    char pad8[0x8];
    s32 unk8;
    char pad14[0x14 - 0xC];
    s32 unk14;
};

extern "C" void func_004735E8(Obj *arg0) {
    arg0->unk14 = 0;
    arg0->unk8 = 1;
}
