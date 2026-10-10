typedef int s32;

extern "C" s32 func_00491690(void *a, void *b, const char *fmt, __builtin_va_list args);

extern "C" s32 func_00490A40(void *a, void *b, const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    return func_00491690(a, b, fmt, args);
}
