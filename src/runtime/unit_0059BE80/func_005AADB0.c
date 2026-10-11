/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib 1.9.0 libc/reent (closer.c / unlinkr.c pattern): a one-argument _xxx_r reentrant
   syscall wrapper; the file has no notice of its own (COPYING.NEWLIB section 9, THIRD_PARTY.md). */
struct _reent {
    int _errno;
};

extern int D_006D62F8; /* errno */
extern int close(int fd);

int func_005AADB0(struct _reent *ptr, int fd) {
    int ret;

    D_006D62F8 = 0;
    if ((ret = close(fd)) == -1 && D_006D62F8 != 0)
        ptr->_errno = D_006D62F8;
    return ret;
}
