extern "C" const char *func_00490230(const char *s, int *out)
{
    char c = *s;
    if ((unsigned int)(c - '0') >= 10)
        return s;
    *out = 0;
    while ((unsigned int)((c = *s) - '0') < 10) {
        s++;
        *out = *out * 10 + c - '0';
    }
    return s;
}
