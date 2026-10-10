/* compiler: ee-gcc2.9-991111 */
extern int func_005B19B0(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize,
                         void *recv, int rsize, void *end, void *arg);
extern int func_00590950(const char *fmt, ...);
extern char D_00882DC0[];
extern int D_00882EC0[];
extern char D_006CF498[];

int func_0058FAC8(int arg)
{
    D_00882EC0[1] = arg;
    if (func_005B19B0(D_00882DC0, 0x80001304, 0, D_00882EC0, 0x90, D_00882EC0, 0x90, 0, 0) < 0) {
        func_00590950(D_006CF498);
        return 0;
    }
    return D_00882EC0[0];
}
