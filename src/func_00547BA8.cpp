extern "C" unsigned char D_0086C912;
extern "C" float func_00548228(int *a, int *b, int *c);

extern "C" float func_00547BA8(int *a, int *b, int *c)
{
    if (!D_0086C912) {
        if (a)
            *a = 0;
        if (b)
            *b = 0;
        if (c)
            *c = 0;
        return 0.0f;
    }
    return func_00548228(a, b, c);
}
