extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_003D62A8(void *arg0, int arg1) {
    SPEC_DATABASE__CarEquipments__setVariationOrder(arg0, 2);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
