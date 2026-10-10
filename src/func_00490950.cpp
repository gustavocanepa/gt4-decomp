extern "C" void func_00491418(void *mgr, const char *fmt, __builtin_va_list args, int one, int zero);

extern "C" void func_00490950(void *mgr, const char *fmt, ...)
{
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_00491418(mgr, fmt, args, 1, 0);
}
