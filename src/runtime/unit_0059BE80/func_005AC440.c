/* compiler: ee-gcc2.96-no-strict-aliasing */
/* newlib 1.9.0 libc/reent (openr.c / execr.c pattern): a three-argument _xxx_r reentrant syscall
   wrapper with an int result; the file has no notice of its own (COPYING.NEWLIB section 9). */
struct _reent {
    int _errno;
};

extern int D_006D62F8; /* errno */
extern int lseek(int a, void *b, int c);

int func_005AC440(struct _reent *ptr, int a, void *b, int c) {
    int ret;

    D_006D62F8 = 0;
    if ((ret = lseek(a, b, c)) == -1 && D_006D62F8 != 0)
        ptr->_errno = D_006D62F8;
    return ret;
}
