struct Src {
    unsigned char kind;
    unsigned char count;
    unsigned char pad[2];
    unsigned char a[4];
    unsigned char b[4];
};

struct Dst {
    float a[4];
    float b[4];
    char rest[1];
};

extern "C" void func_00359A38(void *out, int n, float *a, float *b, int mode, int extra);

extern "C" void func_00366B28(Dst *dst, Src *src, int flag, float sa, float sb)
{
    unsigned char *ib = src->b;
    float *oa = dst->a;
    void *rest = dst->rest;
    unsigned char *ia = src->a;
    float *ob = dst->b;
    int n = src->count;
    int i;
    for (i = 0; i < n; i++) {
        oa[i] = ia[i] * sa;
        ob[i] = ib[i] * sb;
    }
    return func_00359A38(rest, n, oa, ob, flag ? 2 : 0, 0);
}
