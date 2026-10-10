extern "C" char *func_004B9768(char *dst, unsigned short c, int flags);

extern "C" char *func_004B9880(char *out, const unsigned short *src, int n)
{
    char *dst = out;
    while (n-- > 0)
        dst = func_004B9768(dst, *src++, 1);
    *dst = 0;
    return out;
}
