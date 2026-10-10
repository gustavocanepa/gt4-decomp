struct Names { const char *n[4]; };
extern "C" const Names D_006C8E88;
extern "C" char *func_005A6AB0(char *dst, const char *src);
extern "C" void func_0055F490(unsigned int i, char *dst, int n);

extern "C" void func_00566310(unsigned int i, char *dst, int n)
{
    Names t = D_006C8E88;
    if (i < 4)
        func_005A6AB0(dst, t.n[i]);
    else
        func_0055F490(i, dst, n);
}
