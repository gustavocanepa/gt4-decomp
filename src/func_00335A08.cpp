extern "C" void *func_005F30A0(void);
extern "C" char D_00678670[];

extern "C" void func_00335A08(void *arg0)
{
    func_005F30A0();
    *(char **)((char *)arg0 + 0x12C) = D_00678670;
}
