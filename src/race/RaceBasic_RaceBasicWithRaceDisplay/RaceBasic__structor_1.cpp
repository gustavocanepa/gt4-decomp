extern "C" void RacePS2Base__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceBasic__vtable;

extern "C" void RaceBasic__structor_1(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x64) = &RaceBasic__vtable;
    RacePS2Base__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
