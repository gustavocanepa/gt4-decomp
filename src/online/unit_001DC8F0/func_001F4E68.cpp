extern void *func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern int func_004F6888(char *);
extern char D_00645570[];

void *func_001F4E68(void *arg0)
{
    while (!func_004F6888(D_00645570))
        mUpdateContext__Sync(1);
    return func_001F1368(arg0);
}
