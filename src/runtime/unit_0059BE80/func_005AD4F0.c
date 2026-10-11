/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib 1.9.0 libc/reent/readr.c or writer.c (_read_r / _write_r, `long ret` = 64-bit long in this
   build); the file has no notice of its own (COPYING.NEWLIB section 9, THIRD_PARTY.md). */
struct _reent {
    int _errno;
};

extern int D_006D62F8; /* errno */
extern int read(int fd, void *buf, unsigned int cnt);

long func_005AD4F0(struct _reent *ptr, int fd, void *buf, unsigned int cnt) {
    long ret;

    D_006D62F8 = 0;
    if ((ret = read(fd, buf, cnt)) == -1 && D_006D62F8 != 0)
        ptr->_errno = D_006D62F8;
    return ret;
}
