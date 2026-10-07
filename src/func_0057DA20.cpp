extern "C" void func_0057DD28(int arg0, int arg1, __builtin_va_list args);

extern "C" void func_0057DA20(int arg0, int arg1, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, arg1);
    func_0057DD28(arg0, arg1, args);
}
