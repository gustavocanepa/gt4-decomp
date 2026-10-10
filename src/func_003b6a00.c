struct R { char pad[0x119c]; int v[1]; };
extern void func_003BB930(int *, char *, int);
void func_003B6A00(char *p, int i, int x) {
    int *a = (int *)(p + 0x119c);
    int *e;
    e = a + i;
    *e = x;
    func_003BB930(a, p + 0x1158, i);
}
