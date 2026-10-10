/* compiler: ee-gcc2.9-991111 */
extern char D_0087E480[]; /* client data */
extern char D_0087E500[]; /* send buffer */
extern int D_0087FA40[];  /* receive buffer */
extern char D_006CF378[];
extern void func_0058D748(void *arg);
extern int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize,
                         void (*end)(void *), void *arg); /* sceSifCallRpc */
extern int func_005B0750(const char *fmt, ...);        /* printf */

int func_0058E1B8(void)
{
    if (func_005B19B0(D_0087E480, 0x35, 0, D_0087E500, 0x30, D_0087FA40, 4, func_0058D748, 0) != 0) {
        func_005B0750(D_006CF378);
        return -0x5B;
    }
    return D_0087FA40[0];
}
