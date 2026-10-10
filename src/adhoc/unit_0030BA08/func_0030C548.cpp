extern const char D_006D0E78[];
#define isalpha(c) ((D_006D0E78 + 1)[(int)(c)] & 3)
#define isalnum(c) ((D_006D0E78 + 1)[(int)(c)] & 7)

extern "C" int func_0030C548(const char *p)
{
    if (*p == '/') return 1;
    if (isalpha(*p)) {
        p++;
        while (isalnum(*p) && *p) p++;
    }
    if (*p == ':' && p[1] == '/') return 1;
    return 0;
}
