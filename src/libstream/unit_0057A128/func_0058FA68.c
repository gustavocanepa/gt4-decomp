/* compiler: ee-gcc2.9-991111 */
extern char D_00882DC0[];       /* SifRpcClientData_t */
extern unsigned int D_00882EC0[]; /* rpc buffer */
extern int func_005B19B0(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize,
                         void *recv, int rsize, void *end_func, void *end_param); /* sceSifCallRpc */

unsigned int func_0058FA68(void) {
    unsigned int *buf = D_00882EC0;
    if (func_005B19B0(D_00882DC0, 0x80001305, 0, buf, 0x90, buf, 0x90, 0, 0) < 0)
        return 0;
    return buf[1];
}
