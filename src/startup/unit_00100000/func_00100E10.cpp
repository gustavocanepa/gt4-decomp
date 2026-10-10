extern "C" void *func_00109448(void *arg0);
extern "C" char D_00659B70[];

struct func_00100E10_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_00100E10(struct func_00100E10_arg0 *arg0)
{
    func_00109448(arg0);
    arg0->unk8 = D_00659B70;
}
