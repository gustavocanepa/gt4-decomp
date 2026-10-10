extern "C" int func_0057F238(const char *a, const char *b);
extern const char D_006A3560[];
extern const char D_006A3568[];
extern const char D_006A3570[];

extern "C" int func_003DCF10(const char *s) {
    if (func_0057F238(s, D_006A3560) == 0)
        return 0;
    if (func_0057F238(s, D_006A3568) == 0)
        return 1;
    if (func_0057F238(s, D_006A3570) == 0)
        return 2;
    return 3;
}
