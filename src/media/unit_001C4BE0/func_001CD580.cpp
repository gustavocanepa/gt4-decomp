extern "C" const char *func_001CC958(void);
extern "C" char *func_005A609C(char *dst, const char *src);
extern "C" int func_0057F260(const char *s);

extern "C" void func_001CD580(char *buf, int c)
{
    char *name = buf + 1;
    buf[0] = '/';
    func_005A609C(name, func_001CC958());
    buf += func_0057F260(name) + 1;
    if (c > 0)
        *buf++ = c;
    buf[0] = '*';
    buf[1] = 0;
}
