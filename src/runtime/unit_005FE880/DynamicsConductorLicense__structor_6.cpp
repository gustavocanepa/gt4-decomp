typedef int s32;

extern "C" void DynamicsConductor__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *DynamicsConductorLicense__vtable;

struct DynamicsConductorLicense__structor_6_arg0 {
    char pad0[0x10140];
    void *unk10140;
};

extern "C" void DynamicsConductorLicense__structor_6(struct DynamicsConductorLicense__structor_6_arg0 *arg0, s32 arg1) {
    arg0->unk10140 = &DynamicsConductorLicense__vtable;
    DynamicsConductor__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
