struct S { char pad[0x38]; char *arr; char pad2[0x75]; unsigned char flag; };
char *func_004C86E0(struct S *p, int i) {
    if (p == 0 || p->flag == 0) return 0;
    return p->arr + i * 0x28;
}
