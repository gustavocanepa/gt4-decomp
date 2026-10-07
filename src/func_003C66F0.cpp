typedef int s32;

struct Obj003C66F0 {
    char pad0[0x14];
    s32 unk14;
    char pad1[0x24 - 0x14 - 4];
    char *unk24;
};

extern "C" void func_003C6860(char *arg0, s32 arg1);

extern "C" void func_003C66F0(Obj003C66F0 *arg0, s32 arg1) {
    func_003C6860(arg0->unk24 + arg1 * 0x10, arg0->unk14);
}
