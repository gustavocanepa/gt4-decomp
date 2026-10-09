extern "C" void *mModelSet__structor_0(void *arg0);
extern "C" char mModelSetPS2__vtable[];

extern "C" void mModelSetPS2__structor_0(void *arg0)
{
    mModelSet__structor_0(arg0);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = mModelSetPS2__vtable;
}
