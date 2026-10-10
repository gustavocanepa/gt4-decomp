/* compiler: ee-gcc2.9-991111 */
extern int D_00658354;
extern char D_00889AC0[];
extern int D_00889B40[];
extern int D_00889B00[];

int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

unsigned int func_005B6168(int value)
{
    if (D_00658354 < 0)
        return 0;
    D_00889B40[0] = value;
    if (func_005B19B0(D_00889AC0, 8, 0, D_00889B40, 4, D_00889B00, 4, 0, 0) < 0)
        return 0xFFFFFFFFU;
    return D_00889B00[0];
}
