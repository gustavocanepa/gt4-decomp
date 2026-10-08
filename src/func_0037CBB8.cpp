extern "C" void *func_00378AE0(void *arg0);
extern "C" char D_0067A8A0[];

extern "C" void func_0037CBB8(void *arg0)
{
    func_00378AE0(arg0);
    *(int *)((char *)arg0 + 0x180) = 0;
    *(void **)((char *)arg0 + 0x0) = D_0067A8A0;
}
