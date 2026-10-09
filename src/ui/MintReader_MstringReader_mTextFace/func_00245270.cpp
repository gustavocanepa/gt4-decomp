typedef int s32;

struct Obj {
    char pad0[0xF4];
    s32 unkF4;
    char pad1[0x104 - 0xF8];
    s32 unk104;
    char pad2[0x114 - 0x108];
    s32 unk114;
};

extern "C" void func_002B7310(s32 arg0);

extern "C" void func_00245270(struct Obj *arg0) {
    struct Obj *s0 = arg0;

    s0->unkF4 = 0;
    func_002B7310(s0->unk104);
    s0->unk114 = 1;
}
