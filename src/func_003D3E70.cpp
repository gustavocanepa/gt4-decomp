typedef int s32;

struct Obj {
    char pad[0x30];
    s32 unk30;
    char pad2[0x68 - 0x34];
    s32 unk68;
};

extern "C" void func_003D3E70(Obj *arg0, s32 arg1) {
    arg0->unk30 = arg1;
    arg0->unk68 = 0;
}
