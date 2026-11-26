/* compiler: ee-gcc2.9-991111-01 */
/* Inferred: the SDK's small formatter behind its sprintf/snprintf family (callers 005B0610,
   005B0698, ...). Each character goes through out(ctx, &remain, c), whose return value is
   counted; out(ctx, &remain, 0) terminates. It supports the flags - + 0 space #, a width, a
   precision (also as *), the sizes l (64-bit) and h, and the conversions d i u o x X p c s e f
   (e and f print through func_005AF678; NULL strings print "(null)" without being counted).
   Numbers are built backwards in buf; prefix holds the sign or the 0x/0X. */
/* This compiler ships no headers: va_list and va_arg as gcc 2.9x's va-mips.h defines them for
   the 64-bit EABI without double-precision FP registers (each argument takes an 8-byte slot). */
typedef char *va_list;
#define va_arg(ap, t) (*(t *)(void *)((ap += 8) - 8))

#define LEFT 0x1      /* - */
#define PLUS 0x2      /* + */
#define ZERO 0x4      /* 0 */
#define SPACE 0x8     /* ' ' */
#define ALT 0x10      /* # */
#define PREC 0x20     /* .precision given */
#define LONG 0x40     /* l */
#define SHORT 0x80    /* h */
#define CHAR 0x100    /* a single character (%c or an unknown conversion) */

extern char D_006D2430[]; /* "0123456789abcdef" */
extern char D_006D2448[]; /* "0123456789ABCDEF" */
extern int func_005AF678(int (*out)(void *, int *, int), void *ctx, int *remain, double x);

int func_005AF850(int (*out)(void *, int *, int), void *ctx, int remain, const char *fmt, va_list ap)
{
    char buf[32];
    char prefix[32];
    char *end = &buf[31];
    char *p;
    char *start;
    int flags, width, prec, plen, len, i;
    int count = 0;
    int padc;
    const char *digits;
    unsigned long n;
    long sn;
    float f;
    const char *s;

    while (*fmt) {
        flags = 0;
        width = 0;
        prec = 0;
        plen = 0;
        if (*fmt == '%') {
        next:
            fmt++;
            switch (*fmt) {
            case '-':
                flags |= LEFT;
                goto next;
            case '+':
                flags |= PLUS;
                goto next;
            case '0':
                flags |= ZERO;
                goto next;
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                i = 0;
                do {
                    i = i * 10 + (*fmt - '0');
                    fmt++;
                } while (*fmt >= '0' && *fmt <= '9');
                width = i;
                if (*fmt == 0)
                    goto done;
                fmt--;
                goto next;
            case '.':
                fmt++;
                flags |= PREC;
                if (*fmt == '*') {
                    i = va_arg(ap, int);
                    prec = i < -1 ? -1 : i;
                    goto next;
                }
                i = 0;
                while (*fmt >= '0' && *fmt <= '9') {
                    i = i * 10 + (*fmt - '0');
                    fmt++;
                }
                prec = i < -1 ? -1 : i;
                if (*fmt == 0)
                    goto done;
                fmt--;
                goto next;
            case ' ':
                flags |= SPACE;
                goto next;
            case '#':
                flags |= ALT;
                goto next;
            case 'l':
                flags |= LONG;
                goto next;
            case 'h':
                flags |= SHORT;
                goto next;
            case 'o':
                if (flags & LONG)
                    n = va_arg(ap, unsigned long);
                else if (flags & SHORT)
                    n = va_arg(ap, unsigned short);
                else
                    n = va_arg(ap, unsigned int);
                p = end;
                if (n == 0) {
                    if (!(flags & PREC) || prec != 0)
                        *p-- = '0';
                } else {
                    do {
                        *p-- = '0' + (n & 7);
                        n >>= 3;
                    } while (n);
                    if (flags & ALT)
                        *p-- = '0';
                }
                start = p + 1;
                len = end - p;
                break;
            case 'x':
                digits = D_006D2430;
                if (flags & ALT) {
                    prefix[0] = '0';
                    prefix[1] = 'x';
                    plen = 2;
                }
                goto hex;
            case 'X':
                digits = D_006D2448;
                if (flags & ALT) {
                    prefix[0] = '0';
                    prefix[1] = 'X';
                    plen = 2;
                }
            hex:
                if (flags & LONG)
                    n = va_arg(ap, unsigned long);
                else if (flags & SHORT)
                    n = va_arg(ap, unsigned short);
                else
                    n = va_arg(ap, unsigned int);
                p = end;
                if (n == 0) {
                    plen = 0;
                    if (!(flags & PREC) || prec != 0)
                        *p-- = '0';
                } else {
                    do {
                        *p-- = digits[n & 0xF];
                        n >>= 4;
                    } while (n);
                }
                start = p + 1;
                len = end - p;
                break;
            case 'd':
            case 'i':
                if (flags & LONG)
                    sn = va_arg(ap, long);
                else if (flags & SHORT)
                    sn = va_arg(ap, short);
                else
                    sn = va_arg(ap, int);
                p = end;
                if (sn >= 0) {
                    if (flags & PLUS) {
                        prefix[0] = '+';
                        plen = 1;
                    } else if (flags & SPACE) {
                        prefix[0] = ' ';
                        plen = 1;
                    }
                } else {
                    prefix[0] = '-';
                    plen = 1;
                }
                if (sn == 0) {
                    if (!(flags & PREC) || prec != 0)
                        *p-- = '0';
                } else {
                    if (sn < 0)
                        sn = -sn;
                    while (sn) {
                        *p-- = '0' + sn % 10;
                        sn /= 10;
                    }
                }
                start = p + 1;
                len = end - p;
                break;
            case 'u':
                if (flags & LONG)
                    n = va_arg(ap, unsigned long);
                else if (flags & SHORT)
                    n = va_arg(ap, unsigned short);
                else
                    n = va_arg(ap, unsigned int);
                p = end;
                if (n == 0) {
                    if (!(flags & PREC) || prec != 0)
                        *p-- = '0';
                } else {
                    do {
                        *p-- = '0' + n % 10;
                        n /= 10;
                    } while (n);
                }
                start = p + 1;
                len = end - p;
                break;
            case 'e':
            case 'f':
                f = va_arg(ap, double);
                if (f == 0.0f) {
                    count += out(ctx, &remain, '0');
                } else {
                    count += func_005AF678(out, ctx, &remain, f);
                }
                goto done;
            case 's':
                s = va_arg(ap, const char *);
                if (s == 0) {
                    out(ctx, &remain, '(');
                    out(ctx, &remain, 'n');
                    out(ctx, &remain, 'u');
                    out(ctx, &remain, 'l');
                    out(ctx, &remain, 'l');
                    out(ctx, &remain, ')');
                    goto done;
                }
                p = (char *)s;
                if (flags & PREC) {
                    for (i = 0; i < prec && *p++; i++)
                        ;
                    len = i;
                } else {
                    len = 0;
                    while (*p) {
                        p++;
                        len++;
                    }
                }
                start = (char *)s;
                break;
            case 'c':
                flags |= CHAR;
                prec = 1;
                p = end;
                n = va_arg(ap, char);
                *p-- = n;
                start = p + 1;
                len = end - p;
                break;
            case 'p':
                n = va_arg(ap, unsigned int);
                digits = D_006D2430;
                p = end;
                if (n == 0) {
                    if (!(flags & PREC) || prec != 0)
                        *p-- = '0';
                } else {
                    do {
                        *p-- = digits[n & 0xF];
                        n >>= 4;
                    } while (n);
                }
                prefix[0] = '0';
                prefix[1] = 'x';
                plen = 2;
                start = p + 1;
                len = end - p;
                break;
            default:
                if (*fmt == 0)
                    goto done;
                flags |= CHAR;
                prec = 1;
                p = end;
                *p-- = *fmt;
                start = p + 1;
                len = end - p;
                break;
            }

            if (len < prec)
                prec -= len;
            else
                prec = 0;
            width = width - len - plen - prec;
            p = start + len;
            if (flags & CHAR) {
                padc = ' ';
                if ((flags & ZERO) && width > 0)
                    padc = '0';
            } else {
                padc = ' ';
                if ((flags & (ZERO | PREC)) == ZERO && width > 0)
                    padc = '0';
            }
            if (flags & LEFT) {
                for (i = 0; i < plen; i++)
                    count += out(ctx, &remain, prefix[i]);
                for (i = 0; i < prec; i++)
                    count += out(ctx, &remain, '0');
                while (start < p)
                    count += out(ctx, &remain, *start++);
                for (i = 0; i < width; i++)
                    count += out(ctx, &remain, ' ');
            } else if (flags & ZERO) {
                if (padc == '0') {
                    for (i = 0; i < plen; i++)
                        count += out(ctx, &remain, prefix[i]);
                    for (i = 0; i < width; i++)
                        count += out(ctx, &remain, padc);
                } else {
                    for (i = 0; i < width; i++)
                        count += out(ctx, &remain, padc);
                    for (i = 0; i < plen; i++)
                        count += out(ctx, &remain, prefix[i]);
                }
                for (i = 0; i < prec; i++)
                    count += out(ctx, &remain, '0');
                while (start < p)
                    count += out(ctx, &remain, *start++);
            } else {
                for (i = 0; i < width; i++)
                    count += out(ctx, &remain, padc);
                for (i = 0; i < plen; i++)
                    count += out(ctx, &remain, prefix[i]);
                for (i = 0; i < prec; i++)
                    count += out(ctx, &remain, '0');
                while (start < p)
                    count += out(ctx, &remain, *start++);
            }
        } else if (*fmt != 0) {
            count += out(ctx, &remain, *fmt);
        }
    done:
        if (*fmt)
            fmt++;
    }
    out(ctx, &remain, 0);
    return count;
}
