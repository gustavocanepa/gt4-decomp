extern int D_00623A34;
extern char D_00846948[];
extern char D_00846950[];

extern "C" void func_00576100(void *mutex);
extern "C" void func_00576140(void *mutex);
extern "C" int func_00579330(void *obj);
extern "C" int func_00579358(void);

extern "C" int func_00461F88(void)
{
    if (D_00623A34 == 0)
        return func_00579358();
    void *mutex = D_00846948;
    func_00576100(mutex);
    int r = func_00579330(D_00846950);
    func_00576140(mutex);
    return r;
}
