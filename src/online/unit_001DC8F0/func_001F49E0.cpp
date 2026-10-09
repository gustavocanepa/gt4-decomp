struct Handle {
    void *p;
    char pad[0xC];
};

extern char D_00645570[];
extern int func_004F5B10(void *);
extern char *func_004F5D00(void *, int);
extern void func_00215298(int);
extern int func_001F1368(void *);
extern "C" void func_002ED590(Handle *, int *);
extern "C" Handle *func_002EFBF0(Handle *);
extern "C" void func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED5A8(Handle *, Handle *);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_002FC870(Handle *, int);

static inline void add_int(void *array, Handle *v, Handle *tmp, int value)
{
    func_002FE278(v, value);
    func_002EEEB0(tmp, array, v);
    func_00309378(tmp, 2);
    func_002FC870(v, 2);
}

Handle *func_001F49E0(Handle *ret, void *ctx)
{
    Handle list;
    Handle row;
    Handle tmp;
    Handle v1;
    Handle v2;
    Handle v3;
    int zero;
    int count;
    int i;

    while (!func_004F5B10(D_00645570))
        func_00215298(1);
    if (!func_001F1368(ctx)) {
        zero = 0;
        func_002ED590(ret, &zero);
        return ret;
    }
    func_002EFBF0(&list);
    count = *(int *)(*(char **)(D_00645570 + 0x5A8) + 0x5B30);
    for (i = 0; i < count; i++) {
        char *entry = func_004F5D00(D_00645570, i);
        Handle *prow = &row;
        Handle *pt = &tmp;
        func_002EFBF0(prow);
        add_int(prow->p, &v1, pt, *(int *)(entry + 0x1C));
        add_int(prow->p, &v2, pt, *(int *)(entry + 0x20));
        add_int(prow->p, &v3, pt, *(int *)(entry + 0x24));
        func_002EEEB0(pt, list.p, prow);
        func_00309378(pt, 2);
        func_002ED5C0(prow, 2);
    }
    func_002ED5A8(ret, &list);
    func_002ED5C0(&list, 2);
    return ret;
}
