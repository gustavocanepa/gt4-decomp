extern "C" void *func_00415410(void *arg0);
extern "C" char D_006864D8[];

struct S00415470 {
    char pad[0x4C];
    void *unk4C;
};

extern "C" void func_00415470(S00415470 *arg0)
{
    func_00415410(arg0);
    arg0->unk4C = D_006864D8;
}
