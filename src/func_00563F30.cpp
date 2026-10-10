extern int D_00654D80;
extern int D_00654D84;
extern int D_00654DB8;

extern "C" void func_00564508(void *x);
extern "C" int func_00563F98(int n);
extern "C" void func_00563680(void *x);

extern "C" void func_00563F30(void *x) {
    func_00564508(x);
    int n = D_00654D80 * D_00654D84;
    if (D_00654DB8 != 3)
        n >>= 1;
    while (func_00563F98(n) >= 0)
        ;
    return func_00563680(x);
}
