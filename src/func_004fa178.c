struct S { char pad[0xEE0]; int n; int v[1]; };
int func_004FA178(struct S *s, int i) {
    int *pn = &s->n;
    int *e;
    if (i < 0 || i >= *pn) return -1;
    e = s->v + i;
    return *e;
}
