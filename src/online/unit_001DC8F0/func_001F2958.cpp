extern void *func_001F1368(void *);
extern void func_00215298(int);
extern int func_004F19D8(char *);
extern char D_00645570[];

void *func_001F2958(void *arg0)
{
    while (!func_004F19D8(D_00645570))
        func_00215298(1);
    return func_001F1368(arg0);
}
