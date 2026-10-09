typedef int s32;

struct S004CFA28 {
    char pad0[0x14];
    void (*unk14)(s32 arg0);
};

extern "C" void func_004CFA28(struct S004CFA28 *arg0, s32 arg1) {
    arg0->unk14(arg1);
}
