extern char D_00645570[];
extern int func_004F3C70(void *, int);
extern char *func_004F3EF8(void *, int);
extern void mUpdateContext__Sync(int);
extern int func_001F1368(void *);

int func_001F61D8(void *ctx, int id)
{
    while (!func_004F3C70(D_00645570, id))
        mUpdateContext__Sync(1);
    if (!func_001F1368(ctx)) {
        return -1;
    }
    if (*(int *)(*(char **)(D_00645570 + 0x5A8) + 0x5B30) == 0) {
        return -1;
    }
    return *(int *)(func_004F3EF8(D_00645570, 0) + 0x48);
}
