typedef unsigned short wchar16;

static inline int wstrlen(const wchar16 *s)
{
    int n = 0;
    while (s[n] != 0)
        n++;
    return n;
}

extern "C" int func_004B48E8(const wchar16 *s, int c)
{
    int count = 0;
    int len = wstrlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == c)
            count++;
    }
    return count;
}
