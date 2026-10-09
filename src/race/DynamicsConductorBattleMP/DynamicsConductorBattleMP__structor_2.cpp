extern "C" void *DynamicsConductor__structor_0(void *arg0);
extern "C" char DynamicsConductorBattleMP__vtable[];

extern "C" void DynamicsConductorBattleMP__structor_2(void *arg0)
{
    DynamicsConductor__structor_0(arg0);
    *(void **)((char *)arg0 + 0x10140) = DynamicsConductorBattleMP__vtable;
}
