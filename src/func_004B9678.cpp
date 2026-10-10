extern "C" int func_004B95D0(const unsigned char **src, int n);

extern "C" unsigned short *func_004B9678(unsigned short *dst, const unsigned char *src)
{
    unsigned short *d = dst;
    while (*src) {
        if ((*d++ = func_004B95D0(&src, 1)) == 0)
            return 0;
    }
    *d = 0;
    return dst;
}
