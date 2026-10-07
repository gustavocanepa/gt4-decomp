extern "C" void *func_0038A660(void *arg0);
extern "C" char D_00677608[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void func_005F2A08(void *arg0)
{
    func_0038A660(arg0);
    ((S003F15B0 *)arg0)->unk64 = D_00677608;
}
