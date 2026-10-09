struct SearchCtx {
    int a;
    int b;
};

extern "C" void *func_00606F98(void *begin, void *end, SearchCtx *ctx, int flag);
extern "C" int func_0057F238(int arg0, int arg1);

extern "C" void *func_00606E58(void *arg0, char *arg1, int arg2)
{
    char *s0 = arg1 + (arg2 << 3);
    SearchCtx ctx;
    void *s1;

    ctx.a = (int)arg0;
    ctx.b = (int)arg1;
    s1 = func_00606F98(arg1, s0, &ctx, 0);
    if ((s1 != s0) && (func_0057F238(ctx.a, *(int *)s1) == 0)) {
        return s1;
    }
    return 0;
}
