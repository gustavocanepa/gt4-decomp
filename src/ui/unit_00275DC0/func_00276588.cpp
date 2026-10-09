extern "C" void func_00240398(void *arg0, void *arg1);
extern "C" void func_002765D0(void *arg0, void *arg1);

extern "C" void func_00276588(void *arg0, void *arg1) {
    void *s0 = arg0;
    void *s1 = arg1;
    int local = 0;
    func_00240398(s0, &local);
    func_002765D0(s0, s1);
}
