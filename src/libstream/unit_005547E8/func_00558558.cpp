typedef int s32;

extern "C" void func_00578480(s32 arg0);

struct Obj00558558 {
    char pad0[0x78C];
    s32 unk78C;
    char pad1[0x798 - 0x78C - 4];
    s32 unk798;
};

extern "C" void func_00558558(struct Obj00558558 *arg0) {
    arg0->unk78C = 0;
    func_00578480(arg0->unk798);
}
