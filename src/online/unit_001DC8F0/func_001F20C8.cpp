extern void *func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern int func_004F1740(char *);
extern char D_00645570[];

void *func_001F20C8(void *arg0)
{
    while (!func_004F1740(D_00645570))
        mUpdateContext__Sync(1);
    return func_001F1368(arg0);
}
