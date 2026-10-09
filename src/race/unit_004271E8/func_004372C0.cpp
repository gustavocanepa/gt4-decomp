typedef int s32;

struct Obj {
    char pad[0x113C];
    s32 unk113C;
};

extern char D_00846380[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_004372C0(struct Obj *arg0) {
    func_0057B1A8(D_00846380, arg0->unk113C);
}
