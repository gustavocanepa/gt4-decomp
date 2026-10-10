struct Arg {
    int a;
    int b;
    char *p;
};

extern "C" float func_00477460(void *v);
extern "C" void func_00480FA0(Arg *arg, void *ctx);

extern "C" float func_0047BAE8(void *ctx, Arg *arg)
{
    float v;
    if (ctx != 0) {
        v = func_00477460(arg->p - 8);
    } else {
        v = 0.0f;
    }
    func_00480FA0(arg, ctx);
    if (v < 0.0f) {
        return (float)(int)(v + -0.5f);
    }
    return (float)(int)(v + 0.5f);
}
