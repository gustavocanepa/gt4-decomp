extern "C" void *mDefine__structor_0(void *arg0);
extern "C" void *func_00323D08(void *arg0);
extern "C" char mAttributeDefine__vtable[];

extern "C" void *mAttributeDefine__structor_0(void *arg0)
{
    void *s0 = arg0;
    mDefine__structor_0(s0);
    *(void **)((char *)s0 + 0x4) = mAttributeDefine__vtable;
    return func_00323D08((char *)s0 + 0xC);
}
