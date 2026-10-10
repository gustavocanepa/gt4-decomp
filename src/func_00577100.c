extern int func_0058B370(int a, int b, int c, int *out);
extern void func_00577F80(void);

int func_00577100(int a, int b, int c)
{
    int out;
    while (func_0058B370(a, b, c, &out) < 0)
        func_00577F80();
    return out;
}
