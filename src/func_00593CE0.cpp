/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::scan.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern "C" int func_005956A0(char *buf, const char *fmt, __builtin_va_list args, int flags);

extern "C" int func_00593CE0(char *buf, const char *fmt, ...)
{
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    int r = func_005956A0(buf, fmt, args, 0);
    __builtin_va_end(args);
    return r;
}
