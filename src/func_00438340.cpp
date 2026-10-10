extern "C" int func_0057F238(const char *a, const char *b); /* strcmp */

extern "C" int func_00438340(const char **list, const char *s)
{
    for (int i = 0; list[i]; i++) {
        if (func_0057F238(s, list[i]) == 0)
            return i;
    }
    return -1;
}
