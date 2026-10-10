/* compiler: ee-gcc2.9-991111 */
extern int D_00658354;
extern char D_00889AC0[];
extern int D_00889B40[];
extern int D_00889B00[];

int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

int func_005B5E10(int a0, int a1, int a2)
{
    if (D_00658354 < 0)
        return 0;
    D_00889B40[0] = a1;
    D_00889B40[1] = a0;
    D_00889B40[2] = a2;
    if (func_005B19B0(D_00889AC0, 4, 0, D_00889B40, 0xC, D_00889B00, 4, 0, 0) < 0)
        return 0;
    return D_00889B00[0];
}
