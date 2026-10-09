typedef int s32;

struct Obj {
    char pad[0x6D4];
    s32 unk6D4;
    char pad2[0x7B0 - 0x6D4 - 4];
    s32 unk7B0;
};

extern "C" void func_0035DCF0(Obj *arg0) {
    arg0->unk6D4 = 0;
    arg0->unk7B0 = 0;
}
