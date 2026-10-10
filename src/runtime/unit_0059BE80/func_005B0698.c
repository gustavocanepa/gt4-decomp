/* compiler: ee-gcc2.9-991111 */
/* This compiler ships no headers: va_list and va_start as gcc 2.9x's va-mips.h defines them for
   the EABI without double-precision FP registers (a pointer into the saved argument registers). */
typedef char *va_list;
#define va_start(ap, last)                                    \
    (ap = (va_list)__builtin_next_arg(last) -                 \
          (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8))

typedef struct Ctx {
    char *buf;
    int pad[3];
} Ctx;

extern int func_005B0568();
extern int func_005AF850(int (*)(), Ctx *, const char *, int, va_list);

int func_005B0698(char *buf, const char *fmt, int x, ...) {
    Ctx ctx;
    va_list args;
    va_start(args, x);
    ctx.buf = buf;
    return func_005AF850(func_005B0568, &ctx, fmt, x, args);
}
