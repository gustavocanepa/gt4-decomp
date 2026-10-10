extern "C" void *mDefine__structor_0(void *arg0);
extern "C" void *func_00323D08(void *arg0);
extern "C" char mStaticDefine__vtable[];

struct mStaticDefine__structor_0_s0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *mStaticDefine__structor_0(void *arg0)
{
    void *s0 = arg0;
    mDefine__structor_0(s0);
    ((struct mStaticDefine__structor_0_s0 *)s0)->unk4 = mStaticDefine__vtable;
    return func_00323D08((char *)s0 + 0xC);
}
