extern "C" void *func_00578F10(void *arg0);
extern "C" char D_00659B88[];

struct func_005C2418_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_005C2418(struct func_005C2418_arg0 *arg0)
{
    func_00578F10(arg0);
    arg0->unk8 = D_00659B88;
}
