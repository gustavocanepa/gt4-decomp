extern "C" void *func_0046CC38(void *arg0);
extern "C" char D_00660D98[];

struct S001C7698 {
    char pad[0x11D0];
    void *unk11D0;
};

extern "C" void func_001C7698(S001C7698 *arg0)
{
    func_0046CC38(arg0);
    arg0->unk11D0 = D_00660D98;
}
