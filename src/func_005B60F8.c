/* compiler: ee-gcc2.9-991111 */
extern int D_00658354;
extern char D_00889AC0[];
extern unsigned int D_00889B00[];

int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize,
                  void *end, void *arg);

unsigned int func_005B60F8(void)
{
    if (D_00658354 < 0)
        return 0;
    if (func_005B19B0(D_00889AC0, 7, 0, 0, 0, D_00889B00, 4, 0, 0) < 0)
        return 0xFFFFFFFF;
    return D_00889B00[0];
}
