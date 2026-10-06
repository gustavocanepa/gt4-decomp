extern void *func_001F1368(void *);
extern void func_00215298(int);
extern int func_004F74A0(char *, int, int);
extern char D_00645570[];

void *func_001F96F0(void *arg0, int arg1, int arg2)
{
    while (!func_004F74A0(D_00645570, arg1, arg2))
        func_00215298(1);
    return func_001F1368(arg0);
}
