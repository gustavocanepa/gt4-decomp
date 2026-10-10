/* compiler: ee-gcc2.96-as2004 */
static inline int wlen(const unsigned short *s)
{
    int n = 0;
    while (*s) {
        s++;
        n++;
    }
    return n;
}

static inline int charSize(const unsigned short *s)
{
    return 1;
}

extern "C" int func_004B4950(const unsigned short *s)
{
    int len = wlen(s);
    int count = 0;
    for (int i = 0; i < len; i += charSize(s + i))
        count++;
    return count;
}
