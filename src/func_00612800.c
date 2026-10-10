struct S { short pad; unsigned short v; };
int func_00612800(struct S *p) { int x = p->v; return (x >> 4) & 0xf; }
