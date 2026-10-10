extern "C" float func_002736B0(int n)
{
    int p; for (p = 1; p <= 1024 && p < n; p <<= 1) ; return (float)n / p;
}
