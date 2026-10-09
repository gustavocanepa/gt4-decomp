extern void *func_001F1368(void *);
extern void func_00215298(int);
extern int func_005006C8(char *, int);
extern char D_00645570[];

void *func_001F64E8(void *arg0, int arg1)
{
    while (!func_005006C8(D_00645570, arg1))
        func_00215298(1);
    return func_001F1368(arg0);
}
