struct R { int a, b, c, n; long long v[1]; };
long long func_00430528(struct R *p, int i) {
    long long *e;
    if (i < 0 || i >= p->n) return -1;
    e = p->v + i;
    return *e;
}
