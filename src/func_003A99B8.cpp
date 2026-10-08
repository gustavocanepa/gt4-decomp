extern "C" void *func_003A4280(void *arg0);
extern "C" char D_0067F220[];

extern "C" void func_003A99B8(void *arg0)
{
    func_003A4280(arg0);
    *(int *)((char *)arg0 + 0x68) = 0;
    *(void **)((char *)arg0 + 0x14) = D_0067F220;
}
