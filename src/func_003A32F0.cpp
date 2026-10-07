extern "C" void *func_003A3130(void *arg0);
extern "C" char D_0067E7D0[];

extern "C" void func_003A32F0(void *arg0)
{
    func_003A3130(arg0);
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = D_0067E7D0;
}
