extern "C" void *func_0055A790(void *arg0);
extern "C" char D_00689AB8[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void func_0055AD88(void *arg0)
{
    func_0055A790(arg0);
    ((S003F15B0 *)arg0)->unk64 = D_00689AB8;
}
