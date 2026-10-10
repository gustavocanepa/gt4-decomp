/* compiler: ee-gcc2.9-991111 */
extern int D_00655EEC;
extern int D_00655ED0;
extern int D_00655F20;
extern char D_00657A40[];
extern int D_006570C0[];
extern char D_006CE2D0[];

int func_00580AD0(int a);
void func_005ADCC0(int sema);
int func_005B0750(const char *fmt, ...);
int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *arg);

int func_00582590(void)
{
    int r;
    if (func_00580AD0(2) == 0)
        return -1;
    if (func_005B19B0(D_00657A40, 12, 0, 0, 0, D_006570C0, 4, 0, 0) < 0) {
        func_005ADCC0(D_00655EEC);
        return -1;
    }
    r = *(int *)((unsigned int)D_006570C0 | 0x20000000);
    func_005ADCC0(D_00655EEC);
    if (D_00655ED0 >= 2)
        func_005B0750(D_006CE2D0);
    return r;
}
