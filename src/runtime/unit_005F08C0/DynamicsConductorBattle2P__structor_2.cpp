typedef int s32;

extern "C" void DynamicsConductor__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *DynamicsConductorBattle2P__vtable;

extern "C" void DynamicsConductorBattle2P__structor_2(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x10140) = &DynamicsConductorBattle2P__vtable;
    DynamicsConductor__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
