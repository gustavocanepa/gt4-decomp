extern "C" void *func_003B05A8(void *arg0);
extern "C" void *func_003B0A00(void *arg0);
extern char D_0067FB50[];

extern "C" void *func_003B1858(void *arg0)
{
    void *s0 = arg0;
    func_003B0A00(s0);
    *(void **)((char *)s0 + 0x7DC) = D_0067FB50;
    return func_003B05A8((char *)s0 + 0x7E0);
}
