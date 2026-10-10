extern "C" void *func_0057B2B8(void);
extern "C" void *func_00574D78(void *arg0);
extern "C" char D_00689E98[];

struct func_00578E28_arg0 {
    char pad0[0x18];
    void *unk18;
};

extern "C" void *func_00578E28(void *arg0)
{
    func_0057B2B8();
    ((struct func_00578E28_arg0 *)arg0)->unk18 = D_00689E98;
    return func_00574D78((char *)arg0 + 0x1C);
}
