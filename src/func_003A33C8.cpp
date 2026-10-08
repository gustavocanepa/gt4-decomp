extern "C" void *func_003A32F0(void *arg0);
extern "C" char D_0067E7A8[];

extern "C" void func_003A33C8(void *arg0)
{
    func_003A32F0(arg0);
    *(void **)((char *)arg0 + 0x4) = D_0067E7A8;
    *(int *)((char *)arg0 + 0xC) = 0;
}
