struct Thread {
    int sema;
    char pad4[0x3C];
    int arg0;
    int arg1;
};

extern Thread D_0086F8C0;
extern "C" void func_00578500(int sema);
extern "C" void func_00578168(Thread *t, int a, int b, int c, int d);

extern "C" void func_00551400(int arg0, int arg1)
{
    Thread *t = &D_0086F8C0;
    func_00578500(t->sema);
    t->arg0 = arg0;
    t->arg1 = arg1;
    func_00578168(t, 0x5, 0, 0, 0);
}
