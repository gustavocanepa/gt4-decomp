/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_file_setbuf.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Buf {
    int f0;
    char *f4;
    char *f8;
    char *fC;
    char *f10;
    char *f14;
    char *f18;
    char *base;
};

extern "C" int func_00594E70(Buf *b);

extern "C" Buf *func_0059AFE8(Buf *b) {
    if (func_00594E70(b) == 0) {
        return 0;
    }
    char *p = b->base;
    b->f18 = p;
    b->f14 = p;
    b->f10 = p;
    b->fC = p;
    b->f4 = p;
    b->f8 = p;
    return b;
}
