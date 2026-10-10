struct Thread {
    int sema;
    char pad4[0x7C];
    int arg0;
    int arg1;
};

extern Thread D_0086CB80;
extern "C" void func_00578500(int sema);
extern "C" void func_00578168(Thread *t, int a, int b, int c, int d);

extern "C" void func_005485D8(int arg0, int arg1)
{
    Thread *t = &D_0086CB80;
    func_00578500(t->sema);
    t->arg0 = arg0;
    t->arg1 = arg1;
    func_00578168(t, 2, 1, 0, 0);
}
