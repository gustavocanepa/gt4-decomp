extern "C" void func_001FC378(void *arg0, void *arg1);
extern "C" void func_0021CB30(void *arg0, void *arg1);

extern "C" void func_0021CAE8(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_001FC378(s0, &local);
    func_0021CB30(s0, s1);
}
