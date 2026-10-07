extern "C" void *func_001CC000(void *arg0);
extern "C" char D_006615F8[];

struct S00415470 {
    char pad[0x4C];
    void *unk4C;
};

extern "C" void func_005D14C0(S00415470 *arg0)
{
    func_001CC000(arg0);
    arg0->unk4C = D_006615F8;
}
