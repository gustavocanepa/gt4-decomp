extern "C" void *mFadeActor__structor_0(void *arg0);
extern "C" void *func_00105250(char *arg0);
extern "C" char mMCFileActor__vtable[];

struct mMCFileActor__structor_0_s0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *mMCFileActor__structor_0(void *arg0)
{
    void *s0 = arg0;
    mFadeActor__structor_0(s0);
    ((struct mMCFileActor__structor_0_s0 *)s0)->unk4 = mMCFileActor__vtable;
    return func_00105250((char *)s0 + 0x40);
}
