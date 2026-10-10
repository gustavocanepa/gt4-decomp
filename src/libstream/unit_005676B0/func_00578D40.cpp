extern "C" void *func_0057B2B8(void);
extern "C" void *func_00576090(void *arg0);
extern "C" char D_00689E80[];

struct func_00578D40_arg0 {
    char pad0[0x18];
    void *unk18;
};

extern "C" void *func_00578D40(void *arg0)
{
    func_0057B2B8();
    ((struct func_00578D40_arg0 *)arg0)->unk18 = D_00689E80;
    return func_00576090((char *)arg0 + 0x1C);
}
