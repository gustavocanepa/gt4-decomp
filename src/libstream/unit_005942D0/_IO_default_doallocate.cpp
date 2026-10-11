/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_default_doallocate.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern "C" char *malloc(int size);
extern "C" void _IO_setb(void *self, char *begin, char *end, int own);

extern "C" int _IO_default_doallocate(void *self) {
    char *buf = malloc(0x400);
    if (buf == 0) {
        return -1;
    }
    _IO_setb(self, buf, buf + 0x400, 1);
    return 1;
}
