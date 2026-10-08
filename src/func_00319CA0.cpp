extern "C" void *func_003194F0(void *arg0);
extern "C" void *func_00323D08(void *arg0);
extern "C" char D_00676168[];

extern "C" void *func_00319CA0(void *arg0)
{
    void *s0 = arg0;
    func_003194F0(s0);
    *(void **)((char *)s0 + 0x4) = D_00676168;
    return func_00323D08((char *)s0 + 0xC);
}
