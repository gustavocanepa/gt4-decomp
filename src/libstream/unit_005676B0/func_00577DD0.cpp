typedef int s32;

struct S00577DD0 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" void func_00577A30(struct S00577DD0 *arg0, s32 arg1);

extern "C" void func_00577DD0(struct S00577DD0 *arg0) {
    func_00577A30(arg0, arg0->unk8);
}
