struct S {
    char pad0[0xCC];
    int *ptr;
    char pad1[0xE8 - 0xCC - 4];
    unsigned int idx;
};

extern "C" int func_002B49B8(S *arg0, unsigned int arg1) {
    S *p = (S *)((char *)arg0 + arg0->idx * 0x10);
    int *ptrval = p->ptr;
    int off = arg1 * 4;
    char *resptr = (char *)ptrval + off;
    return *(int *)resptr;
}
