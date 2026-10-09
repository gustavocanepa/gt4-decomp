extern "C" void *DynamicsConductor__structor_0(void *arg0);
extern "C" char DynamicsConductorFreePractice__vtable[];

extern "C" void DynamicsConductorFreePractice__structor_1(void *arg0)
{
    DynamicsConductor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x10140) = DynamicsConductorFreePractice__vtable;
}
