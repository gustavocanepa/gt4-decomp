/* compiler: ee-gcc2.9-991111 */
extern char D_00882DC0[];
extern int D_00882EC0[];

int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

int func_0058F728(void) {
    func_005B19B0(D_00882DC0, 0x80001363, 0, D_00882EC0, 0x90, D_00882EC0, 0x90, 0, 0);
    return D_00882EC0[0];
}
