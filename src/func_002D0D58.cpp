extern "C" void *func_00204F10(void *arg0);
extern "C" char D_00670B38[];

extern "C" void func_002D0D58(void *arg0)
{
    func_00204F10(arg0);
    *(int *)((char *)arg0 + 0xB0) = 0;
    *(void **)((char *)arg0 + 0x4) = D_00670B38;
}
