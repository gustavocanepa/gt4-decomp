extern "C" void *func_00386E08(void *arg0);
extern "C" char D_0067BAD8[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void func_00387570(void *arg0)
{
    func_00386E08(arg0);
    ((S003F15B0 *)arg0)->unk64 = D_0067BAD8;
}
