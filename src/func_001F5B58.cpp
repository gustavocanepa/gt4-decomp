extern void *func_001F1368(void *);
extern void func_00215298(int);
extern int func_004F5050(char *, int);
extern char D_00645570[];

void *func_001F5B58(void *arg0, int arg1)
{
    while (!func_004F5050(D_00645570, arg1))
        func_00215298(1);
    return func_001F1368(arg0);
}
