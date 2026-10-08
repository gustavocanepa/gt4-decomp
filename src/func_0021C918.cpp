extern "C" void *func_001FC5A8(void *arg0);
extern "C" char D_00664150[];

extern "C" void func_0021C918(void *arg0)
{
    func_001FC5A8(arg0);
    *(int *)((char *)arg0 + 0x28) = 0;
    *(void **)((char *)arg0 + 0x4) = D_00664150;
}
