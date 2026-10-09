extern "C" void *mComposite__structor_0(void *arg0);
extern "C" char mScrollPinch__vtable[];

extern "C" void mScrollPinch__structor_0(void *arg0)
{
    mComposite__structor_0(arg0);
    *(int *)((char *)arg0 + 0xB0) = 0;
    *(void **)((char *)arg0 + 0x4) = mScrollPinch__vtable;
}
