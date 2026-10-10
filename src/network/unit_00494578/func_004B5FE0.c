struct S { char pad[0x858]; int idx; };
void func_004B5FE0(struct S *s) {
    char *e = (char *)s + (1 - s->idx) * 0x41C;
    int n;
    e += 0x20;
    n = *(int *)(e + 0x214);
    if (n > 0) {
        char *q = e + n * 8;
        *(short *)(*(char **)(e + 8) + *(short *)(q + 0x216) * 2) = 0;
    }
}
