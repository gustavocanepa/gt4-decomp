extern "C" void *func_003BB340(void *arg0);
extern "C" void *func_003D6268(void *arg0);
extern "C" char D_00683920[];

extern "C" void *func_003E9A08(void *arg0)
{
    func_003BB340(arg0);
    *(void **)((char *)arg0 + 0x12C) = D_00683920;
    return func_003D6268((char *)arg0 + 0x130);
}
