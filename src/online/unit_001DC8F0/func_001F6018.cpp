extern char D_00645570[];
extern char D_006959D8[];
extern int func_004F37C0(void *, const char *);
extern void func_00215298(int);
extern void func_001F1368(void *);

/* Strings carry their length 16 bytes before the text. */
static inline const char *terminate(char **str)
{
    char *s = *str;
    int len = ((int *)s)[-4];
    if (len == 0) return D_006959D8;
    s[len] = 0;
    return *str;
}

void func_001F6018(void *ctx, char **str)
{
    while (!func_004F37C0(D_00645570, terminate(str)))
        func_00215298(1);
    func_001F1368(ctx);
}
