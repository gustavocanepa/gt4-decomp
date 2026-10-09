extern "C" void *hObject__structor_0(void);
extern "C" void *func_00560548(void *arg0);
extern "C" char mNetConf__vtable[];

extern "C" void *mNetConf__structor_0(void *arg0)
{
    hObject__structor_0();
    *(void **)((char *)arg0 + 4) = mNetConf__vtable;
    return func_00560548((char *)arg0 + 0x10);
}
