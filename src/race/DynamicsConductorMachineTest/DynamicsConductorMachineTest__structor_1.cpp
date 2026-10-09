extern "C" void *DynamicsConductor__structor_0(void *arg0);
extern "C" char DynamicsConductorMachineTest__vtable[];

extern "C" void DynamicsConductorMachineTest__structor_1(void *arg0)
{
    DynamicsConductor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x10140) = DynamicsConductorMachineTest__vtable;
}
