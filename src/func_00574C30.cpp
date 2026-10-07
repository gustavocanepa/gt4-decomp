extern "C" void func_00574C90(const char *fmt, __builtin_va_list args);

extern "C" void func_00574C30(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_00574C90(fmt, args);
}
