extern "C" void *func_0057B2E8(void);
extern "C" void *func_00574D78(void *arg0);
extern "C" char D_00689E98[];

extern "C" void *func_00578E60(void *arg0)
{
    func_0057B2E8();
    *(void **)((char *)arg0 + 0x18) = D_00689E98;
    return func_00574D78((char *)arg0 + 0x1C);
}
