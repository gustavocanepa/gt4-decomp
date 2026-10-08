extern "C" void *func_0020B520(void *arg0);
extern "C" void *func_00105250(char *arg0);
extern "C" char D_0065CA80[];

extern "C" void *func_00173430(void *arg0)
{
    void *s0 = arg0;
    func_0020B520(s0);
    *(void **)((char *)s0 + 0x4) = D_0065CA80;
    return func_00105250((char *)s0 + 0x40);
}
