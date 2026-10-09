extern "C" void *hObject__structor_0(void);
extern "C" void *func_002273C8(void *arg0);
extern "C" char mShell__vtable[];

extern "C" void *mShell__structor_0(void *arg0)
{
    hObject__structor_0();
    *(void **)((char *)arg0 + 4) = mShell__vtable;
    return func_002273C8((char *)arg0 + 0x10);
}
