extern "C" void *func_003D5CF8(void *arg0);
extern "C" char D_00685168[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void func_003F15B0(void *arg0)
{
    func_003D5CF8(arg0);
    ((S003F15B0 *)arg0)->unk64 = D_00685168;
}
