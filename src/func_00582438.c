/* compiler: ee-gcc2.9-991111 */
extern int D_00655EEC;
extern char D_00657A40[];
extern int D_006570C0[];

int func_00580AD0(int a);
void func_005ADCC0(int sema);
int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

int func_00582438(void)
{
    int r;
    if (func_00580AD0(1) == 0)
        return -1;
    if (func_005B19B0(D_00657A40, 3, 0, 0, 0, D_006570C0, 4, 0, 0) < 0) {
        func_005ADCC0(D_00655EEC);
        return -1;
    }
    r = *(int *)((unsigned int)D_006570C0 | 0x20000000);
    func_005ADCC0(D_00655EEC);
    return r;
}
