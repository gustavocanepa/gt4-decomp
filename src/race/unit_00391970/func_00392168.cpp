extern "C" void func_004632A0(void *arg0, void *arg1);
extern "C" void SePlayer__Initialize(void *arg0, void *arg1, int arg2);

extern "C" void func_00392168(void *arg0, void *arg1) {
    void *s0 = arg0;
    int local;
    func_004632A0(arg1, &local);
    SePlayer__Initialize(s0, &local, 0);
}
