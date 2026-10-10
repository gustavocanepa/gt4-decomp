struct NameId {
    const char *name;
    int id;
};

extern char D_00645570[];
extern NameId D_00696FD0[];
extern "C" int func_0057F238(const char *, const char *);
extern int func_004F59D8(void *, int);
extern void mUpdateContext__Sync(int);
extern int func_001F1368(void *);

int func_001F48E0(void *ctx, const char *name)
{
    int id = 0xFFFFFF;
    int i;

    for (i = 0; i < 10; i++) {
        if (func_0057F238(D_00696FD0[i].name, name) == 0) {
            id = D_00696FD0[i].id;
            break;
        }
    }
    if (id == 0xFFFFFF) {
        return 0;
    }
    while (!func_004F59D8(D_00645570, id))
        mUpdateContext__Sync(1);
    return func_001F1368(ctx);
}
