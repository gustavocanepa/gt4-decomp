extern "C" void func_0057DBE8(const char *fmt, __builtin_va_list args);

extern "C" void func_0057D9C0(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_0057DBE8(fmt, args);
}
