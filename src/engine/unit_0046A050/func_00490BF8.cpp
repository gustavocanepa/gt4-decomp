typedef int s32;

extern "C" s32 func_00490BF8(const char *s) {
    s32 n;
    if (!s)
        return 0;
    n = 1;
    for (; *s; s++)
        if (*s == '\n')
            n++;
    return n;
}
