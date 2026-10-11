/* libio (GNU iostream library, gcc 2000-10-03 snapshot): skip_ws.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* newlib-style isspace(): (_ctype_ + 1)[c] & _S with _ctype_ a const char array (_ctype_) */
extern const char _ctype_[];
extern int _IO_getc(void *fp);

int func_00591330(void *fp) {
    int c;
    while ((c = _IO_getc(fp)) != -1 && ((_ctype_ + 1)[c] & 8))
        ;
    return c;
}
