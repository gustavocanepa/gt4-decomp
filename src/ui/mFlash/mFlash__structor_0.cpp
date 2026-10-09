extern "C" void *mData__structor_0(void *arg0);
extern "C" char mFlash__vtable[];

extern "C" void mFlash__structor_0(void *arg0)
{
    mData__structor_0(arg0);
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = mFlash__vtable;
}
