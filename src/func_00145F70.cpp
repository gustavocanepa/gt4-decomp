extern const char *D_006188B0[];
extern "C" int func_0057F238(const char *a, const char *b); /* strcmp */

/* Index of a name in a null-terminated table, -1 when absent. */
extern "C" int func_00145F70(const char *name)
{
    const char **p = D_006188B0;
    int i = 0;
    for (; *p != 0; p++, i++) {
        if (func_0057F238(*p, name) == 0)
            return i;
    }
    return -1;
}
