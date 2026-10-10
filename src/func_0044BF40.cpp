struct Obj {
    int a;
    int b;
};

extern "C" void func_0044BBD8(unsigned char *p, unsigned char *q, int a, int b);

extern "C" void func_0044BF40(Obj *o, unsigned char *base, int n)
{
    for (unsigned char *p = base + n - 8; p >= base; p--)
        func_0044BBD8(p, p, o->a, o->b);
}
