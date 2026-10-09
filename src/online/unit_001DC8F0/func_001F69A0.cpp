extern char D_00645570[];
extern void func_004FFB38(void *);
extern void func_004FEEF8(void *, int, int);
extern void func_004FEFC8(void *);
extern int func_001F1368(void *);

int func_001F69A0(void *ctx, int a, int b)
{
    func_004FFB38(D_00645570);
    if (!func_001F1368(ctx)) {
        return -1;
    }
    func_004FEEF8(D_00645570, a, b);
    if (!func_001F1368(ctx)) {
        return -1;
    }
    func_004FEFC8(D_00645570);
    return -1;
}
