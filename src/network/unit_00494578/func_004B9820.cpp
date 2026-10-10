extern "C" char *func_004B9768(char *dst, unsigned short c, int mode);

extern "C" char *func_004B9820(char *dst, const unsigned short *src)
{
    char *p = dst;
    while (*src)
        p = func_004B9768(p, *src++, 1);
    *p = 0;
    return dst;
}
