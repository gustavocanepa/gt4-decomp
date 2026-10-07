extern "C" void func_005762F0(const char *fmt, __builtin_va_list args);

extern "C" void func_00574CB8(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_005762F0(fmt, args);
}
