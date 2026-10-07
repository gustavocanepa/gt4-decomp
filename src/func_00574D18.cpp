extern "C" void func_00576350(const char *fmt, __builtin_va_list args);

extern "C" void func_00574D18(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_00576350(fmt, args);
}
