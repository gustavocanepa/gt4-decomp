typedef int s32;

struct S004FAC58 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_004FAC78(s32 arg0, struct S004FAC58 *arg1);

extern "C" void func_004FACC8(struct S004FAC58 *arg0) {
    func_004FAC78(arg0->unk14, arg0);
}
