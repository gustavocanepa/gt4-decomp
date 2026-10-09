/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib _strtoul_r */
extern const char D_006D0E78[];

unsigned long func_005A71A0(rptr, nptr, endptr, base)
    int *rptr;
    const char *nptr;
    char **endptr;
    register int base;
{
    register const char *s = nptr;
    register unsigned long acc;
    register int c;
    register unsigned long cutoff;
    register int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while ((D_006D0E78 + 1)[c] & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = (unsigned long)-1 / (unsigned long)base;
    cutlim = (unsigned long)-1 % (unsigned long)base;
    for (acc = 0, any = 0;; c = *s++) {
        if ((D_006D0E78 + 1)[c] & 4)
            c -= '0';
        else if ((D_006D0E78 + 1)[c] & 3)
            c -= ((D_006D0E78 + 1)[c] & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = (unsigned long)-1;
        *rptr = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);
    return acc;
}
