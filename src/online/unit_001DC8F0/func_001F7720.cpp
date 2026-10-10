extern char D_00645570[];
extern int func_004FD660(void *, int, int, int);
extern void mUpdateContext__Sync(int);
extern void func_001F1368(void *);

void func_001F7720(void *ctx, int a, int b, int c)
{
    while (!func_004FD660(D_00645570, a, b, c))
        mUpdateContext__Sync(1);
    return func_001F1368(ctx);
}
