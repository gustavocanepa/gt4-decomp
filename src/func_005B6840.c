/* compiler: ee-gcc2.9-991111 */
extern char D_00889E80[];
extern int D_00889C80[];

int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);
int func_005B6268(void);
int func_005B6368(void);

int func_005B6840(int value)
{
    if (func_005B6268() < 0)
        return -0x10000;
    if (func_005B6368() != 0)
        return -0x10004;
    D_00889C80[0] = value;
    if (func_005B19B0(D_00889E80, 8, 0, D_00889C80, 4, D_00889C80, 4, 0, 0) < 0)
        return -0x10001;
    return D_00889C80[0];
}
