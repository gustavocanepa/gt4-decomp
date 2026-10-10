struct Desc {
    void (*entry)(void *);
    void *arg;
};

extern "C" int D_0064C3C0;
extern "C" char D_0086C8E0[];
extern "C" void func_005477C8(void *arg);
extern "C" int func_00578B50(int a, int b);
extern "C" int func_00578610(int h);
extern "C" int func_00575098(Desc *d, int prio);
extern "C" void func_005788B8(int h);

extern "C" void func_005477E8(void)
{
    if (D_0064C3C0 == 0) {
        Desc d;
        d.entry = func_005477C8;
        d.arg = D_0086C8E0;
        D_0064C3C0 = func_00575098(&d, func_00578610(func_00578B50(3, 0)));
        func_005788B8(D_0064C3C0);
    }
}
