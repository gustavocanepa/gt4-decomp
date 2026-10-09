extern "C" void *func_003194F0(void *arg0);
extern "C" void *func_00323D08(void *arg0);
extern "C" char D_006756D8[];

extern "C" void *func_0031F540(void *arg0)
{
    void *s0 = arg0;
    func_003194F0(s0);
    *(void **)((char *)s0 + 0x4) = D_006756D8;
    return func_00323D08((char *)s0 + 0xC);
}
