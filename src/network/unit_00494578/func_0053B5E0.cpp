/* strncasecmp (inferred): compares at most n characters of s1 and s2 without regard to ASCII
 * case, through the unit's tolower (func_0053B4E0); returns 0 when they agree up to n, the end
 * of either string or both, else the difference of the lowered characters. tolower is declared
 * const: retail keeps the two characters in registers across its calls instead of reloading. */
extern "C" signed char func_0053B4E0(signed char c) __attribute__((const));

extern "C" int func_0053B5E0(const char *s1, const char *s2, int n) {
    if (n == 0)
        return 0;
    while (n-- != 0 && func_0053B4E0(*s1) == func_0053B4E0(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return func_0053B4E0(*s1) - func_0053B4E0(*s2);
}
