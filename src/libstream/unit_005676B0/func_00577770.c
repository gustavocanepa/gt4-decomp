extern int func_005B6638(int a, int b, int c, int *out);
extern void func_00577F80(void);

int func_00577770(int a, int b, int c)
{
    int out;
    while (func_005B6638(a, b, c, &out) < 0)
        func_00577F80();
    return out;
}
