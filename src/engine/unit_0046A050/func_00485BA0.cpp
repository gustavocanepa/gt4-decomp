extern "C" unsigned int func_0057F260(const char *s);

extern "C" unsigned long func_00485BA0(const char *s)
{
    const unsigned char *end = (const unsigned char *)s + func_0057F260(s);
    unsigned long h = 0;
    for (const unsigned char *p = (const unsigned char *)s; p != end; p++) {
        h += *p;
    }
    h = h + (h << 12) + (h << 24) + (h << 36) + (h << 48);
    for (const unsigned char *q = (const unsigned char *)s; q != end; q++) {
        unsigned long c = *q;
        unsigned long t = h >> 57;
        h <<= 7;
        h |= t;
        h += c;
    }
    return h;
}
