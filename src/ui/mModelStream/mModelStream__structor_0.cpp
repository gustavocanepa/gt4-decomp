extern "C" void *mStream__structor_0(void *arg0);
extern "C" char mModelStream__vtable[];

extern "C" void mModelStream__structor_0(void *arg0)
{
    mStream__structor_0(arg0);
    *(int *)((char *)arg0 + 0x28) = 0;
    *(void **)((char *)arg0 + 0x4) = mModelStream__vtable;
}
