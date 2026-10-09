extern char D_00645570[];
extern char D_00695AE0[];
extern int func_004F7D88(void *, int);
extern int func_004F7E28(void *);
extern int func_004F9410(void *, int);
extern const char *func_001F15A0(void *);
extern "C" int func_005A5A30(char *, int, const char *, ...);
extern void func_00227BE0(int, char *);
extern void func_00215298(int);
extern int func_001F1368(void *);

int func_001F7648(char *ctx, int id)
{
    char line[0x40];
    int result;

    while (!func_004F7D88(D_00645570, id))
        func_00215298(1);
    if (!func_001F1368(ctx)) {
        return 0;
    }
    result = func_004F9410(D_00645570, func_004F7E28(D_00645570));
    if (result == 0) {
        return 0;
    }
    const char *who = func_001F15A0(ctx);
    func_005A5A30(line, 0x40, D_00695AE0, who, func_004F7E28(D_00645570));
    func_00227BE0(*(int *)(ctx + 0x1C0), line);
    return result;
}
