struct Handle {
    void *p;
    char pad[0xC];
};

extern char D_00645570[];
extern int func_004F2660(void *, int, int);
extern void func_00215298(int);
extern int func_001F1368(void *);
extern void func_001F2C88(Handle *, void *, int);
extern "C" void func_002ED590(Handle *, int *);
extern "C" Handle *func_002EFBF0(Handle *);
extern "C" void func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED5A8(Handle *, Handle *);

Handle *func_001F2820(Handle *ret, void *ctx, int a, int b)
{
    Handle list;
    Handle item;
    Handle tmp;
    int zero;
    int count;
    int i;

    while (!func_004F2660(D_00645570, a, b))
        func_00215298(1);
    if (!func_001F1368(ctx)) {
        zero = 0;
        func_002ED590(ret, &zero);
        return ret;
    }
    func_002EFBF0(&list);
    count = *(int *)(*(char **)(D_00645570 + 0x5A8) + 0x5B30);
    for (i = 0; i < count; i++) {
        func_001F2C88(&item, ctx, i);
        func_002EEEB0(&tmp, list.p, &item);
        func_00309378(&tmp, 2);
        func_002ED5C0(&item, 2);
    }
    func_002ED5A8(ret, &list);
    func_002ED5C0(&list, 2);
    return ret;
}
