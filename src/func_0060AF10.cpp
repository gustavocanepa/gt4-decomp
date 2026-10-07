typedef int s32;

struct Obj {
    char pad[0x30];
    s32 unk30;
    s32 unk34;
};

extern "C" void func_0060AF10(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk30 = arg1;
    arg0->unk34 = arg2;
}
