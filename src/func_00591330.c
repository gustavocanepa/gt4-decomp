/* libio (GNU iostream library, gcc 2000-10-03 snapshot): skip_ws.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* newlib-style isspace(): (_ctype_ + 1)[c] & _S with _ctype_ a const char array (D_006D0E78) */
extern const char D_006D0E78[];
extern int func_00596EF0(void *fp);

int func_00591330(void *fp) {
    int c;
    while ((c = func_00596EF0(fp)) != -1 && ((D_006D0E78 + 1)[c] & 8))
        ;
    return c;
}
