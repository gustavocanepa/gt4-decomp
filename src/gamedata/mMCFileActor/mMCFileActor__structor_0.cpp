extern "C" void *mFadeActor__structor_0(void *arg0);
extern "C" void *func_00105250(char *arg0);
extern "C" char mMCFileActor__vtable[];

extern "C" void *mMCFileActor__structor_0(void *arg0)
{
    void *s0 = arg0;
    mFadeActor__structor_0(s0);
    *(void **)((char *)s0 + 0x4) = mMCFileActor__vtable;
    return func_00105250((char *)s0 + 0x40);
}
