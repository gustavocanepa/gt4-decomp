extern "C" void *DynamicsConductor__structor_0(void *arg0);
extern "C" char DynamicsConductorLicense__vtable[];

extern "C" void DynamicsConductorLicense__structor_3(void *arg0)
{
    DynamicsConductor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x10140) = DynamicsConductorLicense__vtable;
}
