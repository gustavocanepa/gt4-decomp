extern "C" int func_00422DC8(int a, int b);

extern "C" int func_00422E10(int n, int *v)
{
    if (n <= 0)
        return 0;
    int r = v[0];
    for (int i = 1; i < n; i++)
        r = func_00422DC8(r, v[i]);
    return r;
}
