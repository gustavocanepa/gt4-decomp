typedef int s32;

extern void *RaceBGMPS2__vtable;
extern "C" void func_00547A88(void *, float);
extern "C" void RaceBGMBase__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceBGMPS2__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &RaceBGMPS2__vtable;
    func_00547A88(arg0, 1.0000000298f);
    RaceBGMBase__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
