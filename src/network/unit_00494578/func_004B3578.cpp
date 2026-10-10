struct Name {
    int data;
    Name(const Name &o);
};

extern "C" unsigned int func_0057F260(const char *s);
extern "C" void func_004B2050(char *dst, const char *src);
extern "C" Name func_004B33D8(void *ctx, int flag, const char *s);

extern "C" Name func_004B3578(void *ctx, const char *s) {
    char *buf = (char *)__builtin_alloca(func_0057F260(s) + 1);
    func_004B2050(buf, s);
    return func_004B33D8(ctx, 1, buf);
}
