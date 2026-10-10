extern char D_00654D40[];

extern "C" void func_00576788(void *m);
extern "C" void func_005767C0(void *m);
extern "C" int func_0058DA38(void *x);
extern "C" void func_00577F80(void);
extern "C" void func_00562618(int *a, int *b);

extern "C" int func_00561E00(void *x) {
    int a, b;
    func_00576788(D_00654D40);
    while (func_0058DA38(x))
        func_00577F80();
    func_00562618(&a, &b);
    func_005767C0(D_00654D40);
    return b;
}
