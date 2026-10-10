/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_default_doallocate.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern "C" char *func_00575DC8(int size);
extern "C" void func_00594A88(void *self, char *begin, char *end, int own);

extern "C" int func_00594F68(void *self) {
    char *buf = func_00575DC8(0x400);
    if (buf == 0) {
        return -1;
    }
    func_00594A88(self, buf, buf + 0x400, 1);
    return 1;
}
