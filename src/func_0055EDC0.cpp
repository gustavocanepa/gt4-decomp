typedef int s32;

struct Obj {
    char pad[0x50];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
};

extern "C" void func_0055EDC0(Obj *arg0) {
    arg0->unk5C = -1;
    arg0->unk58 = 0;
    arg0->unk54 = 0;
    arg0->unk50 = 0;
}
