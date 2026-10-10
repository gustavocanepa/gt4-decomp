struct Thread64 {
    int sema;
    char pad4[0x3C];
    long long arg0;
    long long arg1;
};

extern Thread64 D_0086F700;
extern "C" void func_00578500(int sema);
extern "C" void func_00578168(Thread64 *t, int a, int b, int c, int d);

extern "C" void func_0054F5E0(long long arg0, long long arg1)
{
    Thread64 *t = &D_0086F700;
    func_00578500(t->sema);
    t->arg0 = arg0;
    t->arg1 = arg1;
    func_00578168(t, 0x3, 1, 0, 0);
}
