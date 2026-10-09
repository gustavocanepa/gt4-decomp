typedef int s32;

struct Obj {
    char pad[0x20];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};

extern "C" void func_002D1FF8(Obj *arg0) {
    if (arg0->unk20 != 0) {
        arg0->unk20 = 0;
        arg0->unk24 = 0;
        arg0->unk28 = 0;
        arg0->unk2C = 0;
        arg0->unk30 = 0;
    }
}
