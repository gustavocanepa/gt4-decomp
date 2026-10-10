struct R { short a; unsigned short n; short v[1]; };
short func_0055EF50(struct R *p, int i) {
    short *e;
    if (i >= 0 && i < p->n) { e = p->v + i; return *e; }
    return 0;
}
