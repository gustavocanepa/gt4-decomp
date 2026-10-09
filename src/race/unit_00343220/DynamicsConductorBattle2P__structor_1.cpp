extern "C" void *DynamicsConductor__structor_0(void *arg0);
extern "C" char DynamicsConductorBattle2P__vtable[];

extern "C" void DynamicsConductorBattle2P__structor_1(void *arg0)
{
    DynamicsConductor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x10140) = DynamicsConductorBattle2P__vtable;
}
