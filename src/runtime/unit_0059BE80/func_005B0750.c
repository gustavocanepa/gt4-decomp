/* compiler: ee-gcc2.9-991111 */
/* This compiler ships no headers: va_list and va_start as gcc 2.9x's va-mips.h defines them for
   the EABI without double-precision FP registers (a pointer into the saved argument registers). */
typedef char *va_list;
#define va_start(ap, last)                                    \
    (ap = (va_list)__builtin_next_arg(last) -                 \
          (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8))

extern int func_005B05C0();
extern int func_005B72A8(void);
extern void func_005B72F8(void);
extern int func_005AF850(int (*)(), void *, unsigned int, const char *, va_list);

void func_005B0750(const char *fmt, ...)
{
    int ctx;
    va_list args;
    int state;

    ctx = 0;
    state = func_005B72A8();
    va_start(args, fmt);
    func_005AF850(func_005B05C0, &ctx, 0xFFFFFFFF, fmt, args);
    if (state)
        func_005B72F8();
}
