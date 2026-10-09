extern "C" void RaceBasic__structor_1(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_005F2A38(void *arg0, int arg1) {
    RaceBasic__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
